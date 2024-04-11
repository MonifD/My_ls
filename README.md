# Groupe de nepos_a 1026201

## My_ls

My_ls est un programme en C qui imite la fonctionnalité de la commande Unix "ls". Il peut lister les fichiers et les répertoires, ainsi que fournir des détails tels que les permissions, le propriétaire, la taille et la date de modification des fichiers.

## Fonctionnalités

Affichage des détails (-l) : Le programme peut afficher les détails des fichiers en utilisant l'option -l.
Liste récursive (-R) : Il peut également lister récursivement les sous-répertoires avec l'option -R.
Tri (-r et -t) : Le tri est pris en charge avec les options -r (tri inverse) et -t (tri par date de modification).
Gestion des fichiers cachés (-a et -A) : Les fichiers cachés peuvent être inclus dans la liste avec -a, ou exclus avec -A.
Gestion de liens symboliques (-L) : L'option -L permet de suivre les liens symboliques et de lister les fichiers vers lesquels ils pointent.
Compilation
Vous pouvez compiler le programme en exécutant la commande suivante dans votre terminal :

make

Cela générera un exécutable appelé my_ls.

## Utilisation

Pour utiliser le programme, exécutez-le dans votre terminal avec les options de votre choix, suivies éventuellement du répertoire que vous souhaitez lister :

./my_ls [options] [directory...]
[options] : Les options que vous souhaitez utiliser, telles que -l, -R, -r, -t, -a, -A, -L.
[directory...] : Les répertoires que vous souhaitez lister. Si aucun répertoire n'est spécifié, le répertoire actuel sera listé.

## Exemples

Afficher les détails des fichiers dans le répertoire courant :
./my_ls -l

Listez récursivement tous les fichiers et répertoires dans le répertoire spécifié :
./my_ls -R directory_name

Liste les fichiers par date de modification, du plus récent au plus ancien :
./my_ls -t
