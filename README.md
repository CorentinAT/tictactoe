# TicTacToe - Corentin ALBERT

Bienvenue dans ce morpion super sympa !

J'ai testé le programme sur macOs (puce ARM), en compilant avec GCC 15.1.0 aarch-apple-darwin24. Il se lance en utilisant le pack d'extensions vscode qu'on a vu en cours.

## Organisation du code et fonctionnalités

Les fonctionnalités ne débordent pas des deux modes de jeux imposés. Tout est faisable en lançant le programme normalement (sauf si vous voulez changer la taille du plateau de jeu, alors il faut aller modifier `constants.hpp`).

Le code est divisé en 5 parties :

- `constants.hpp` contient les deux constantes globales du projet : **BOARD_SIZE** et **DEFAULT_CHAR** (le caractère qu'il y a dans une case vide). On peut imaginer modifiers ces variables pour personnaliser le jeu. Si BOARD_SIZE change, alors le nombre de cases à aligner change aussi (si BOARD_SIZE est à 5, alors il faut aligner 5 croix ou 5 ronds pour gagner).
- `player.cpp` / `player.hpp` contiennent les fonctions pour créer un joueur, ainsi que la structure qui le définit. Ce sont des fonctions `create_player` avec différentes déclarations, appelées en fonction du mode de jeu et de l'ordre de création (si c'est le premier ou le deuxième joueur).
- `board.cpp` / `board.hpp` contiennent les fonctions relatives au plateau de jeu. Principalement les vérifications (vérifier si le plateau est rempli, s'il y a 3 symboles alignés d'une manière ou un autre). Il y a aussi la fonction `draw_game_board` qui affiche le plateau.
- `actions.cpp` / `actions.hpp` contiennent les fonctions pour jouer un coup, soit par un joueur, soit par l'ordinateur.
- `main.cpp` contient la structure du programme. C'est lui qui orchestre l'ordre dans lequel les actions sont faites. Il gère le menu, appelle les fonctions de création de joueur, gère l'ordre de placement de symbole et la fin de partie.

## Amélioration

La seule amélioration est celle de l'IA. Voici comment elle se comporte :

- Si elle peut aligner un troisième symbole et gagner, alors elle le fait.
- Sinon, si elle peut m'empêcher de gagner au prochain tour, elle le fait.
- Sinon, elle joue aléatoirement.

Je remet tout de même en avant la possibilité de changer la taille du plateau de jeu en modifiant la variable globale correspondante. Mais je l'ai surtout fait pour avoir un code propre, ça ne correspond pas aux évolutions vers des jeux plus complexes décrites dans la consigne.

## Difficultés rencontrées

Une difficulté que j'ai rencontré est la vérification de victoire, détecter si une ligne, une colonne ou une diagonale est terminée. Il a suffit de se creuser la tête pour trouver des algos qui fonctionnent peu importe la valeur de **BOARD_SIZE**.

Une autre difficulté a été pour à la fin d'une partie, différencier un match nul d'une victoire. Au départ, j'avais une unique fonction qui me disait si le plateau était rempli mais ça ne suffisait pas à savoir si la partie était nulle ou non. J'ai alors ajouté une fonction `is_won` qui m'indique, en utilisant les fonctions dont je parle dans le paragraphe du dessus, si quelqu'un a gagné la partie. Cela me permet de savoir, une fois la partie arrêtée, la conclusion de celle-ci.

Amusez-vous bien !
