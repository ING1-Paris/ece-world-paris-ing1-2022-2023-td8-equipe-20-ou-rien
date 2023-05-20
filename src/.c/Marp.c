/* POUR COMMIT L AVANCEE DE LA PRESENTATION SUR MARP---
marp: true
theme: projet
paginate: true
_paginate: false
---

<script type="module">
  import mermaid from 'https://cdn.jsdelivr.net/npm/mermaid@10/dist/mermaid.esm.min.mjs';
    mermaid.initialize({
        startOnLoad: true,
        theme: 'base',
    });
</script>

<!--
# Style lead only for this slide
_class: lead
_footer: Algorithmique Avancée et Bibliothèque Graphique - 2022-2023
-->

![bg left](./images/fond_ece.png)

*ING1* Projet d'informatique


# ECE World

- Mathéo LEON
- Gabriel GUIET DUPRE
- Jade VIGOUROUX
- Robin PETIT

TD 8 - Equipe 20

---
<br>

![bg](./images/fondd.webp)

# Sommaire
<br>

## - DTI
## - ACD
## - Algorithmes
## - Schémas
## - Contributions GitHub
## - Mini jeux
## - Bilan
## - Sources


---
<br>

# DTI
![bg](./images/fondd.webp)


*Données:* nom des deux personnages, leur skin, ajout de bitmaps, de fichiers audio (.wav) et de fichiers de sauvegarde.
<br>

*Traitement:* choisir son nom, choisir son skin (personnage), chargement des images et des fichiers audios.
<br>

*Interface:* choix du joueur avec la touche entrer, déplacement avec les flèches du clavier, sauvegarde avec la touche s, affichage des statistiques avec la touche h.

---

<br>

# ACD
![bg](./images/fondd.webp)

1. *Tâche:* inscription des joueurs
*Décomposition:* assimilation de chaque joueur à son skin, récupération des noms des joueurs, sauvegarde des chaque données.
<br>

2. *Tâche:* génération des différentes map
*Décomposition:* arrivée sur une première map, qui est le menu principal, puis possibilité de changer de monde, via différentes map créées.
<br>

---
![bg](./images/fondd.webp)
<br>

3. *Tâche:* chargement des différents jeux selon les maps (mondes)
*Décomposition:* chaque map possède ses jeux spécifiques: tous les jeux ne sont pas inscrits sur la même map, car il y a des mondes différents.
<br>

4. *Tâche:* déplacement des joueurs
*Décomposition:* gérer les collisions sur la map, et pour se déplacer, appuyer sur les flèches
<br>

5. *Tâche:* génération de la victoire
*Décomposition:* comparer le résultat de chacun des deux joueurs pour chaque attractions. Celui qui n'a plus de ticket perd.

---
![bg](./images/fondd.webp)
<br>
# Algorithmes


---
![bg](./images/fondd.webp)
<br>

# Schémas

Précisez comment les jeux sont organisés ? Sont-ils dans des fichiers séparés ? Dans des dossiers ? Sont-ils éparpillés dans plusieurs fichiers ?

Quels paramètres prennent les jeux ?  La file d'événement par exemple ? Ou est-ce que chaque jeu crée sa propre file ?

Comment on lance un jeu et comment on revient à la carte à la fin de la partie ?
Comment le classement est-il mis à jour ?


---

<br>

# Contributions GitHub
<br>

- Commit normés
- Prise en main des différentes fonctions de GitHub ( Commit, Push, Pull)
-

![bg right : 80%](images/Graph3.png)

---

![bg 85%](images/Graph2.png)

---

![bgright](images/Graph1.png)

---

![bg right:40%](images/Taupe.PNG)

# Taupe-la !
Réalisé par : **Gabriel GUIET DUPRE*
<br>

Au niveau du décors, les nuages sont afichés avec une méthode de parallaxe. Des taupes apparaissent aléatoirement pendant un temps aléatoire (entre 1sec et 0,2sec). Elles disparaissent ensuite pendant un temps aléatoire, ou disparaissent suite au joueur qui les a éliminé avec le marteau. Le marteau est animé quand il est utilisé.

---

![bg right:40%](images/Taupe.PNG)
<br>

# Taupe-la !
<br>

Utilisation d'un tableau de structure permettant de gérer les taupes. Utilisation d'une clock qui renvoie le temps en micro secondes depuis le début du programme.

---

![bg right:40%](images/ballon.PNG)

<br>

# Tir aux ballons

Réalisé par : **Jade VIGOUROUX*

Les joueurs jouenrt à tour de rôle. Ils ont un temps imparti de 10 sec pour éclater tous les ballons. S'ils y arrivent, le joueur ayant fait le meilleur temps gagne, et si les deux perdent, c'est celui qui a éclaté le plus de ballon qui l'emporte.

---
![bg right:40%](images/ballon.PNG)
<br>

# Tir aux ballons

Utilisation d'un tableau de structure pour les ballons; d'un tableau d'entier pour stocker les déplacement et les positions; et l'utilisation d'une clock qui renvoie le temps en micro secondes depuis le début du programme.

---
![bg right:40%](images/ours.png)

# Traversée de rivière

Réalisé par : **Robin PETIT*

Décrire le fonctionnement du jeu dans les grandes lignes. Comment vous l'avez conçu.
- Les canards vont de la droite à la gauche.
- Lorsqu'ils ont disparu, ils ont 1 chance sur 50 de réapparaitre à droite.
- Les canards vont à une vitesse différente (tirée aléatoirement).
- La collision des canards est détectée.
- etc.

<sup>:bulb: Remplacez les images par des captures d'écran de votre jeu.</sup>

---
![bg right:40%](images/ours.png)

# Traversée de rivière

Pour chaque jeu (bien détailler au moins un jeu par personne), précisez les structures de données (structures importantes, tableaux importants, listes chainées...) et les fonctions importantes (avec leur prototype).

---

![bg right:40%](images/Snake.png)

# Snake

Réalisé par : **Matheo LEON*

Décrire le fonctionnement du jeu dans les grandes lignes. Comment vous l'avez conçu.
- Les canards vont de la droite à la gauche.
- Lorsqu'ils ont disparu, ils ont 1 chance sur 50 de réapparaitre à droite.
- Les canards vont à une vitesse différente (tirée aléatoirement).
- La collision des canards est détectée.
- etc.

<sup>:bulb: Remplacez les images par des captures d'écran de votre jeu.</sup>

---

![bg right:40%](images/Snake.png)

# Snake

Pour chaque jeu (bien détailler au moins un jeu par personne), précisez les structures de données (structures importantes, tableaux importants, listes chainées...) et les fonctions importantes (avec leur prototype).

### Structures

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
classDiagram
    class Canard
    Canard : int x, y
    Canard : int vitesse
    class Canne
    Canne : int x, y
    Canne : Canard* canard
</div>

### Tableaux

- `Canard canards[20]`


---

![bg right:40%](images/JA.png)
<br>

# Japanese Apocalypse
<br>

Réalisé par : **Gabriel GUIET DUPRE*

Le joueur atterit dans un labyrinthe 3D où il doit survivre en tuant tous les monstres. Il y a quatre types de monstres, et le joueur possède deux armes.

---

![bg right:40%](images/JA.png)
<br>

# Japanese Apocalypse
<br>

Utilisation de tableaux de structures pour stocker les adversaires, ainsi que de tableaux d'entiers pour stocker les distances. La programmation orienté objet a été privilégiée. En effet, tout le jeu tient dans un pointeur de structure où toutes les données/structures y sont stockées, pour améliorer la rapidité du jeu.


---
![bg](./images/fondd.webp)
<br>

# Bilan

---

<!--
_class: lead
-->

# Les slides suivantes ne seront pas présentées oralement lors de la soutenance mais doivent figurer dans la présentation. Nous les survolerons rapidement.

---

# Toto

## Tâches réalisées (pour chaque membre de l'équipe)

- `✅ 100%` Tâche 1
- `✅ 80%` Tâche 2
    - Développer ici pourquoi cette tâche n'est pas terminée à 100%. (exemple : on aurait pu améliorer...).
- `❌ 20%` Tâche 3
    - Développer ici pourquoi cette tâche n'a pas été terminée.
- `❌ 20%` Tâche 4
    - Développer ici pourquoi cette tâche n'a pas été terminée.
    - Développer ici pourquoi cette tâche n'a pas été terminée.

---

# Investissement

Si vous deviez vous répartir des points, comment feriez-vous ?

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
pie showData
    "Toto Jojo" : 20
    "Tata Jaja" : 20
    "Tyty Jyjy" : 10
    "Tutu Juju" : 40
    "Titi Jiji" : 10
</div>

---

# Récapitulatif des jeux

| Jeu | Avancement | Problèmes / reste |
| --- | --- | --- |
| Taupe-la ! | 100% | - |
| Tir aux ballons | 100% | - |
| Traversée de rivière | 60% |-|



---

| Jeu | Avancement | Problèmes / reste |
| --- | --- | --- |
| Snake | 100% | - |
| Guitar Hero | 100% | - |
| Japanese Apocalypse | 60% | -|

---

<!--
_class: lead
-->
# Quelques éléments que vous pouvez utiliser à votre guise dans votre présentation

# Schémas et Graphes

Vous pouvez utiliser [Mermaid.js](https://mermaid.js.org/) pour générer des schémas. Regardez la documentation.

 */