# philosophers

Reproduction du problème du dîner des philosophes en C (manipulation des threads et processus) :

- Un nombre X de philosophes est donnée en entrée au programme
- Chaque philosophe est soit en train de manger, de penser ou de dormir dans cet ordre
- Il y a autant de fourchettes sur la table qu'il y a de philosophes
- Chaque philosophe a besoin des deux fourchettes autour de son assiette pour manger
- Un temps pour manger, pour dormir, pour penser et un temps maximum de survie sans manger est donné en entrée de programme
- Les philosophes ne communiquent pas entre eux
Le but est qu'aucun philosophe ne meure ; on évalue la qualité du programme en fonction du temps de survie pour les différents scénarios de paramétrage donnés.

L'exercice est décliné en deux programmes différents :
1 : Chaque philosophe est représenté par un thread, on protège l'utilisation de chaque fourchette par un mutex 
2 : Chaque philosophe est représenté par un thread, toutes les fourchettes sont placées au centre de la table, et le nombre de fourchettes disponible est représenté par un sémaphore
3 : Chaque philosophe est représenté par un processus différent. Toutes les fourchettes sont placées au centre de la table, et le nombre de fourchettes disponible est représenté par un sémaphore
