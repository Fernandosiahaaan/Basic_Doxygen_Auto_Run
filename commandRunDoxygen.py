import subprocess
import shutil
import os

# Path Folder
old_folder = "./docs/html"
new_folder = "./docs"


# Run script using subprocess
try:
    subprocess.run("doxygen doxyfile", shell=True, check=True)
    print("Perintah bash berhasil dijalankan.")
    # Copy file tujuan
    subprocess.run("mv docs/html/* docs/", shell=True, check=True)
    subprocess.run("rm -r docs/html/", shell=True, check=True)

except subprocess.CalledProcessError as e:
    print(f"Error: {e}")
except FileNotFoundError:
    print("Error: Perintah Doxygen tidak ditemukan. Pastikan Doxygen telah diinstal.")
