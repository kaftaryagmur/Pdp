/**
*
* @author Yagmur Kaftar
* <p>
* Main sınıfı ile program başlar
* </p>
*/

package Main;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.List;

import Analyzer.ClassAnalyzer;
import Cloner.RepoCloner;
import Extractor.FileExtractor;

public class Main {
    public static void main(String[] args) {
    	try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("Klonlanacak repository URL'sini girin: ");
            String repositoryUrl = reader.readLine();
            reader.close();

            RepoCloner cloner = new RepoCloner();
            File localRepoDir = cloner.cloneRepository(repositoryUrl);

            FileExtractor extractor = new FileExtractor();
            List<File> javaFiles = extractor.extractJavaFiles(localRepoDir);
            List<File> classFiles = extractor.extractClassFiles(javaFiles);
            
            System.out.println("---------------------------");
            ClassAnalyzer analyzer = new ClassAnalyzer();
            for (File classFile : classFiles) {
                analyzer.analyzeClass(classFile);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

