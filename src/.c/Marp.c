/* POUR COMMIT L AVANCEE DE LA PRESENTATION SUR MARP
---
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

**ING1** Projet d'informatique

# ECE World

Equipe 20

---

# Equipe 20

![bg right:50%](./images/equipe.avif)

- Mathéo LEON
- Gabriel GUIET DUPRE
- Jade VIGOUROUX
- Robin PETIT

---

# ECE World

![bg right:50% 198%](./images/theme.webp)

## Thème

Notre Projet est sur le thème **futuriste**. Nous avons donc décidé de créer plusieurs mondes, qui s'adaptent aux jeux que nous avons choisi de coder. Comme si le joueur pouvait se déplacer, que ce soit dans le temps ou bien dans l'espace.

---

# Carte `1/2`

*Réalisée par : **Toto**, **Tata**.*

Décrire ici les fonctionnalités implémentées : choix joueurs, saisie des noms, affichage des scores/classement... Comment avez-vous fait ? Quels étaient les problèmes rencontrés.

---

# Carte `2/2`

Suite si ça ne tient pas sur une slide.

:bulb: *Vous pouvez faire comme ça à chaque fois qu'une slide ne suffit pas, il vaut mieux 5 slides légères qu'une surchargée.*

---

# Organisation des jeux

Précisez comment les jeux sont organisés ? Sont-ils dans des fichiers séparés ? Dans des dossiers ? Sont-ils éparpillés dans plusieurs fichiers ?

Quels paramètres prennent les jeux ?  La file d'événement par exemple ? Ou est-ce que chaque jeu crée sa propre file ?

Comment on lance un jeu et comment on revient à la carte à la fin de la partie ?
Comment le classement est-il mis à jour ?

---

![bg right:40%](images/peche_canards.jpg)

# Taupe-la !

*Réalisé par : **Toto** (40%), **Tata** (60%).*

Décrire le fonctionnement du jeu dans les grandes lignes. Comment vous l'avez conçu.
- Les canards vont de la droite à la gauche.
- Lorsqu'ils ont disparu, ils ont 1 chance sur 50 de réapparaitre à droite.
- Les canards vont à une vitesse différente (tirée aléatoirement).
- La collision des canards est détectée.
- etc.

<sup>:bulb: Remplacez les images par des captures d'écran de votre jeu.</sup>

---

![bg right:40%](images/peche_canards.jpg)

# Taupe-la !

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

![bg right:40%](images/peche_canards.jpg)

# Taupe-la !

### Graphe d'appel

<br>

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
flowchart LR
    pecheAuxCanards --> initialiserCanards
    initialiserCanards --> positionnerCanard
    pecheAuxCanards --> deplacerCanards
    deplacerCanards --> deplacerCanard
    pecheAuxCanards --> detecterCollisionCanards
</div>

---

![bg right:40%](images/peche_canards.jpg)

# Taupe-la !

### Logigramme

Que vous jugez pertinent (image ou Mermaid.js)


---

![bg right:40%](images/ballon.JPG)

# Tir aux ballons

*Réalisé par : **Toto** (40%), **Tata** (60%).*

Décrire le fonctionnement du jeu dans les grandes lignes. Comment vous l'avez conçu.
- Les canards vont de la droite à la gauche.
- Lorsqu'ils ont disparu, ils ont 1 chance sur 50 de réapparaitre à droite.
- Les canards vont à une vitesse différente (tirée aléatoirement).
- La collision des canards est détectée.
- etc.

<sup>:bulb: Remplacez les images par des captures d'écran de votre jeu.</sup>

---

![bg right:40%](images/ballon.JPG)

# Tir aux ballons

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

![bg right:40%](images/ballon.JPG)

# Tir aux ballons

### Graphe d'appel

<br>

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
flowchart LR
    pecheAuxCanards --> initialiserCanards
    initialiserCanards --> positionnerCanard
    pecheAuxCanards --> deplacerCanards
    deplacerCanards --> deplacerCanard
    pecheAuxCanards --> detecterCollisionCanards
</div>

---

![bg right:40%](images/ballon.JPG)

# Tir aux ballons

### Logigramme

Que vous jugez pertinent (image ou Mermaid.js)


---
![bg right:40%](images/peche_canards.jpg)

# Traversée de rivière

*Réalisé par : **Toto** (40%), **Tata** (60%).*

Décrire le fonctionnement du jeu dans les grandes lignes. Comment vous l'avez conçu.
- Les canards vont de la droite à la gauche.
- Lorsqu'ils ont disparu, ils ont 1 chance sur 50 de réapparaitre à droite.
- Les canards vont à une vitesse différente (tirée aléatoirement).
- La collision des canards est détectée.
- etc.

<sup>:bulb: Remplacez les images par des captures d'écran de votre jeu.</sup>

---

![bg right:40%](images/peche_canards.jpg)

# Traversée de rivière

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

![bg right:40%](images/peche_canards.jpg)

# Traversée de rivière

### Graphe d'appel

<br>

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
flowchart LR
    pecheAuxCanards --> initialiserCanards
    initialiserCanards --> positionnerCanard
    pecheAuxCanards --> deplacerCanards
    deplacerCanards --> deplacerCanard
    pecheAuxCanards --> detecterCollisionCanards
</div>

---

![bg right:40%](images/peche_canards.jpg)

# Traversée de rivière

### Logigramme

Que vous jugez pertinent (image ou Mermaid.js)

---
![bg right:40%](images/peche_canards.jpg)

# Snake

*Réalisé par : **Toto** (40%), **Tata** (60%).*

Décrire le fonctionnement du jeu dans les grandes lignes. Comment vous l'avez conçu.
- Les canards vont de la droite à la gauche.
- Lorsqu'ils ont disparu, ils ont 1 chance sur 50 de réapparaitre à droite.
- Les canards vont à une vitesse différente (tirée aléatoirement).
- La collision des canards est détectée.
- etc.

<sup>:bulb: Remplacez les images par des captures d'écran de votre jeu.</sup>

---

![bg right:40%](images/peche_canards.jpg)

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

![bg right:40%](images/peche_canards.jpg)

# Snake

### Graphe d'appel

<br>

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
flowchart LR
    pecheAuxCanards --> initialiserCanards
    initialiserCanards --> positionnerCanard
    pecheAuxCanards --> deplacerCanards
    deplacerCanards --> deplacerCanard
    pecheAuxCanards --> detecterCollisionCanards
</div>

---

![bg right:40%](images/peche_canards.jpg)

# Snake

### Logigramme

Que vous jugez pertinent (image ou Mermaid.js)

---
![bg right:40%](images/peche_canards.jpg)

# Guitar Hero

*Réalisé par : **Toto** (40%), **Tata** (60%).*

Décrire le fonctionnement du jeu dans les grandes lignes. Comment vous l'avez conçu.
- Les canards vont de la droite à la gauche.
- Lorsqu'ils ont disparu, ils ont 1 chance sur 50 de réapparaitre à droite.
- Les canards vont à une vitesse différente (tirée aléatoirement).
- La collision des canards est détectée.
- etc.

<sup>:bulb: Remplacez les images par des captures d'écran de votre jeu.</sup>

---

![bg right:40%](images/peche_canards.jpg)

# Guitar Hero

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

![bg right:40%](images/peche_canards.jpg)

# Guitar Hero

### Graphe d'appel

<br>

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
flowchart LR
    pecheAuxCanards --> initialiserCanards
    initialiserCanards --> positionnerCanard
    pecheAuxCanards --> deplacerCanards
    deplacerCanards --> deplacerCanard
    pecheAuxCanards --> detecterCollisionCanards
</div>

---

![bg right:40%](images/peche_canards.jpg)

# Guitar Hero

### Logigramme

Que vous jugez pertinent (image ou Mermaid.js)

---

![bg right:40%](images/peche_canards.jpg)

# Japanese Apocalypse

*Réalisé par : **Toto** (40%), **Tata** (60%).*

Décrire le fonctionnement du jeu dans les grandes lignes. Comment vous l'avez conçu.
- Les canards vont de la droite à la gauche.
- Lorsqu'ils ont disparu, ils ont 1 chance sur 50 de réapparaitre à droite.
- Les canards vont à une vitesse différente (tirée aléatoirement).
- La collision des canards est détectée.
- etc.

<sup>:bulb: Remplacez les images par des captures d'écran de votre jeu.</sup>

---

![bg right:40%](images/peche_canards.jpg)

# Japanese Apocalypse

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

![bg right:40%](images/peche_canards.jpg)

# Japanese Apocalypse

### Graphe d'appel

<br>

<div class="mermaid">
%%{init: {'theme':'neutral'}}%%
flowchart LR
    pecheAuxCanards --> initialiserCanards
    initialiserCanards --> positionnerCanard
    pecheAuxCanards --> deplacerCanards
    deplacerCanards --> deplacerCanard
    pecheAuxCanards --> detecterCollisionCanards
</div>

---

![bg right:40%](images/peche_canards.jpg)

# Japanese Apocalypse

### Logigramme

Que vous jugez pertinent (image ou Mermaid.js)

---

# Bilan collectif

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
    - *Développer ici pourquoi cette tâche n'est pas terminée à 100%. (exemple : on aurait pu améliorer...).*
- `❌ 20%` Tâche 3
    - *Développer ici pourquoi cette tâche n'a pas été terminée.*
- `❌ 20%` Tâche 4
    - *Développer ici pourquoi cette tâche n'a pas été terminée.*
    - *Développer ici pourquoi cette tâche n'a pas été terminée.*

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