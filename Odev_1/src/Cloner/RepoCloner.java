/**
*
* @author Yagmur Kaftar
* <p>
* Kullanıcından alınan repo clonlanır
* </p>
*/
package Cloner;

import java.io.File;

public class RepoCloner {
	public File cloneRepository(String repositoryUrl) {
		File localRepoDir = new File("./" + repositoryUrl.substring(repositoryUrl.lastIndexOf("/") + 1));

		if (localRepoDir.exists()) {
			deleteDirectory(localRepoDir);
		}

		try {
			ProcessBuilder builder = new ProcessBuilder("git", "clone", repositoryUrl);
			builder.directory(new File("./"));
			Process process = builder.start();
			int exitCode = process.waitFor();

			if (exitCode == 0) {
				// basarili klonlama
				return new File(localRepoDir.getAbsolutePath());
			} else {
				// basarisiz klonlama
				System.err.println("Depo klonlama işlemi başarısız oldu. Çıkış kodu: " + exitCode);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}

		return null;
	}

	// tekrar klonlama istegi uzerine var olan dosyayi silen fonksiyon
	private static void deleteDirectory(File directory) {
		if (directory.exists()) {
			File[] files = directory.listFiles();
			if (files != null) {
				for (File file : files) {
					if (file.isDirectory()) {
						deleteDirectory(file);
					} else {
						file.delete();
					}
				}
			}
			directory.delete();
		}
	}
}
