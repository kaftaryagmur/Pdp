/**
*
* @author Yagmur Kaftar
* <p>
* Klonanan projeden .java ve ardından sınıf içerikli dosyalar alınır
* </p>
*/

package Extractor;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class FileExtractor {
	public List<File> extractJavaFiles(File repoDirectory) {
		List<File> javaFiles = new ArrayList<>();

		// repository'deki tum dosyalari al
		File[] files = repoDirectory.listFiles();
		if (files != null) {
			for (File file : files) {
				// dosya bir dizin ise icindeki dosyalari da tara
				if (file.isDirectory()) {
					javaFiles.addAll(extractJavaFiles(file));
				} else if (file.getName().endsWith(".java")) {
					javaFiles.add(file);
				}
			}
		} else {
			System.err.println("Dosya okuma hatası");
		}

		return javaFiles;
	}

	public List<File> extractClassFiles(List<File> javaFiles) {
		List<File> classFiles = new ArrayList<>();

		// her bir .java dosyasinin kontrolu
		for (File javaFile : javaFiles) {
			if (containsClassDefinition(javaFile)) {
				classFiles.add(javaFile);
			}
		}

		return classFiles;
	}

	private boolean containsClassDefinition(File javaFile) {
		boolean containsClass = false;
		try (BufferedReader reader = new BufferedReader(new FileReader(javaFile))) {
			String line;
			while ((line = reader.readLine()) != null) {
				// sinif tanimlama
				if (line.contains("class ")) {
					containsClass = true;
					break;
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		return containsClass;
	}
}
