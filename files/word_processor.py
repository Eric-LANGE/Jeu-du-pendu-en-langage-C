"""

Programme Python qui extrait d'un dictionnaire complet, indiqué en paramètre, la liste des mots de plus de 10 caractères, accentuations supprimées.

return: la liste des mots de plus de 10 caractères
rtype: list

"""

import codecs, os
import unicodedata
import timeit

def liste_mots_francais(file_in):
	
	mots = []
	if not os.path.isfile(file_in):
		print("Problème d'arborescence : le dictionnaire {} n'existe pas".format(os.path.join(os.path.abspath(os.curdir), file_in)))
		return []

	with codecs.open(file_in, "r", encoding="utf-8") as fid:
		mots = [mot.strip() for mot in fid.readlines() if len(mot.strip()) >= 10 and '-' not in mot]
		mots = [unicodedata.normalize('NFD', mot).encode('ascii', 'ignore').decode('utf-8').upper() for mot in mots]
		return mots
		

def word_processor(my_list):


	file_out = "Chemin vers le fichier de sortie en .txt"
	

	with open(file_out, 'w') as file_handler:
		for item in my_list:
			file_handler.write(f"{item}\n")
			
		#file_handler.writelines( "%s\n" % item for item in my_list )
		
	return 0
		

def main():

	file_in = "Chemin vers le fichier d'entrée en .txt"
	
	my_list = liste_mots_francais(file_in)
	
	word_processor(my_list)
	
if __name__ == '__main__':
	main()

