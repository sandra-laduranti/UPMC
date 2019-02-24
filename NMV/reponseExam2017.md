1. 5000 blob à l'origine => duplicat ne crée pas de nouveau blob donc 0
2. si diff entre 2 commit sur même branche => merge? => merge conflict

------
technique syncho


1.

    Stop les Interruptions

local_irq_{disable, enable}()

    Desactiver la preemption (Context switch)

preempt_{disable, enable}()


2.  On fait __get_cpu_var, en tant que cpu1, on se fait preempte au milieu d'appel systeme et migre sur cpu2, ou on fait __put_cpu_var et on ecrit (on ecrit pas chez nous)
solution => opérations atomiques


3. nconvénient

On dort donc y a plein d'endroits dans le noyau ou on peut pas l'utiliser  ===> mutex => sleep, scheduler peut virer les trucs qui sleep et ils ne seront jamais "récupérés", vaut mieux utiliser un spin lock qui retry et ne peut pas être viré par scheduler


4. Read-Copy-Update (RCU)

    create a new structure,
    copy the data from the old structure into the new one, and save a pointer to the old structure,
    modify the new, copied, structure update the global pointer to refer to the new structure, and then
    sleep until the operating system kernel determines that there are no readers left using the old structure, for example, in the Linux kernel, by using synchronize_rcu().

------------------------------


struct données et concurrence

1. pas de cas dans les deux sens, 2 compare and swap => perte de l'atomicité de l'ensemble (pas atomique entre 2 cas). Solution => cas en double valeur????

2. a. pour tout n appartenant à la liste secondaire il doit exister un n2 dont le suivant est n

b. lock pour ajout => 2 lock suffisent (un sur element precedent et un sur suivant -en cas de suppression eventuelle du suivant, on le protège le temps de l'insertion pour ne pas pointer sur un truc qui possiblement n'existe plus- ), lock suppression => besoin d'un troisième lock (precedent, current, next)

------------------------------
Mémoire virtuelle

1. Les adresses virtuelles sont les adresses vues par le processeur
• À un instant donnée et pour un cœur donnée, une adresse virtuelle
correspond à zéro ou une adresse physique
• À un instant donnée et pour un cœur donnée, une adresse physique
correspond à zéro, une ou plusieurs adresses virtuelles
• Le nombre d’adresse virtuelles est déterminé par l’architecture du processeur

sur la durée => une adresse virtuelle => plusieurs physiques


2. Automatiquement géré => modification du CS3 (commut) + accès mémoire
manuellement géré => Le processeur fournit une instruction dédiée (invlpg)

-------------------------------

Virtualisation

1. (GVA) addresses virtuelles invitées // (GPA) addresses physiques invitées
"a priori l'hypercall fonctionne mieux" hypercall discute directement avec le superviseur (skip machine hote et cie => tu utilise ta propre table)
Shadowing reflete modif des pages du système guest => logiquement plus de modif (transformer appels guest pour les mettre dans table host)

-------------------------------
Topologie mémoire

4 noeuds
1 noeud => 12 cpu +  16G
1 appli => 16 thread 8G
Tous noeuds numa connectés entre eux

Si appli utilisant les même données de manière répétitive => first touch => tout sur un seul noeud
Si appli utilisant données différentes => réparti sur plusieurs noeuds (que 2? en first touch toujours)

(interleaving => répartition égale sur tous les noeuds)

------------------------------
Garbage Collector

1. a priori miette sémantique a partir de la ligne 6? Garbage collector pas suffisament intelligent pour détecter avant.

2. a priori on ne peut pas dans le cas où un element serait supprimé/ajouté en parallèle?

3. Tri color
  -> tout est blanc au début
  -> on marque ce qui est atteignable depuis la racine en gris
  -> on marque tous les enfants des gris en gris
  -> quand un enfant n'a plus d'enfants => marqué en noir (remontée reccursive)
  -> on collecte ce qui reste en blanc

-------------------------------
ordonnancement

1. Completely Faire Scheduler => arbre rouge noir
2. 
