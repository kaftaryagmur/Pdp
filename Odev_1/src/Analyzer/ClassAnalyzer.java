/**
*
* @author Yagmur Kaftar
* <p>
* Sınıflar üzerinde istenen analizler yapılır
* </p>
*/
package Analyzer;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ClassAnalyzer {
	public void analyzeClass(File javaFile) {
        try (BufferedReader reader = new BufferedReader(new FileReader(javaFile))) {
            String line;
            int javadocCount = 0;
            int otherCommentsCount = 0;
            int codeLineCount = 0;
            int loc = 0;
            int functionCount = 0;

            boolean inJavadoc = false;

            while ((line = reader.readLine()) != null) {
                javadocCount += countJavadocLines(line, inJavadoc);
                otherCommentsCount += countOtherComments(line, inJavadoc);
                codeLineCount += countCodeLines(line, inJavadoc);
                loc++;
                functionCount += countFunctionNumber(line);
                inJavadoc = isInJavadoc(line, inJavadoc);
            }

            printAnalysisResults(javaFile.getName(), javadocCount, otherCommentsCount, codeLineCount, loc, functionCount);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private int countJavadocLines(String line, boolean inJavadoc) {
    	int count = 0;

        if (line.trim().startsWith("/**")) {
            inJavadoc = true;
        }

        if (inJavadoc || line.trim().startsWith("*")) {
            count++;
        }

        if (inJavadoc && line.trim().endsWith("*/")) {
            inJavadoc = false;
        }

        return count;
    }

    private int countOtherComments(String line, boolean inJavadoc) {
        int count = 0;
        if (!inJavadoc && (line.trim().startsWith("//") || line.trim().startsWith("/*"))) {
            count++;
        }
        return count;
    }

    private int countCodeLines(String line, boolean inJavadoc) {
        int count = 0;
        if (!inJavadoc && !(line.trim().startsWith("//") || line.trim().startsWith("/*") || line.trim().isEmpty())) {
            count++;
        }
        return count;
    }

    private int countFunctionNumber(String line) {
        int count = 0;
        Pattern functionPattern = Pattern.compile("^\\s*(public|private|protected)\\s+\\w+\\s+\\w+\\(.*\\)\\s*(\\{|throws).*");
        Matcher functionMatcher = functionPattern.matcher(line);
        if (functionMatcher.find()) {
            count++;
        }
        return count;
    }

    private boolean isInJavadoc(String line, boolean inJavadoc) {
        if (line.trim().startsWith("/**")) {
            return true;
        } else if (inJavadoc && !line.trim().endsWith("*/")) {
            return true;
        } else if (inJavadoc && line.trim().endsWith("*/")) {
            return false;
        }
        return inJavadoc;
    }

    private void printAnalysisResults(String fileName, int javadocCount, int otherCommentsCount, int codeLineCount, int loc, int functionCount) {
        System.out.println("Analiz edilen dosya: " + fileName);
        System.out.println("---------------------------");
        System.out.println("Javadoc yorum satırı sayısı: " + javadocCount);
        System.out.println("Diğer yorum satırı sayısı: " + otherCommentsCount);
        System.out.println("Kod satırı sayısı: " + codeLineCount);
        System.out.println("LOC: " + loc);
        System.out.println("Fonksiyon sayısı: " + functionCount);
    	double yg = ((javadocCount + otherCommentsCount) * 0.8) / functionCount;
        double yh = (double) codeLineCount / functionCount * 0.3; // Changed codeLineCount to LOC
        double commentDeviationPercentage = ((100 * yg) / yh) - 100;
        System.out.println("Yorum sapma yüzdesi: %" + String.format("%.2f", commentDeviationPercentage));
        System.out.println("---------------------------");
    }
}
