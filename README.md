# Arduino

# 0.1 Idée 

J’ai eu l’idée de mettre en place un système de supervision, comme on pourrait en retrouver dansunmilieuindustrieloudanslesmaisonsintelligentes.Lebutserad’aﬃcherdesinformations sur l’écran LCD en fonction d’évènements qui se passent dans le milieu extérieur.

# 0.2 Représentation
-Deux boutons, qui pourraient représenter par exemple deux barrières infrarouges et dont le signal reçu passe de 1 à 0 lorsqu’un objet passe devant.
-Deux potentiomètres. Le premier sert de "consigne" et est réglé par l’utilisateur. Le second représentera un capteur. À titre d’exemple, sur la vidéo à la suite vous verrez un potentiomètre rotatif qui représentera la consigne et un autre sous forme de glissière qui sera le capteur.
-Une LED rouge, nous permettra de faire une alarme visuelle. Elle sera normalement éteinte mais si la valeur du capteur dépasse celle de la consigne alors elle s’allumer

# 0.3  Comportement
de l’écranChaque interface sera affichée pendant cinq secondes à tour de rôle. La première afficheral’état des boutons. Enfin, bien que l’information "consigne/capteur" ne s’affiche que toutes les 5secondes, l’alarme (la LED rouge), elle, est visible à tout moment si la valeur du capteur dépassecelle de la consigne.0.4  MontageJ’ai vaillé à satisfaire ces trois conditions :-Des condensateurs de filtrage pour éviter les rebonds parasites créés par les boutons.-Mettre les potentiomètres sur des entrées analogiques.-Brancher la LED dans le bon sens et ne pas oublier sa résistance de limitation de courant.1
J’ai fais la simulation sur tinkercad voici le lien :https ://www.tinkercad.com/things/krCowrN62yz-mon-projet 

Voici le lien du montage que j’ai effectué sur Tincerkard :

# 0.5  Code 

# 0.5.1  Les variables
-5 pour les entrées/sorties (2 boutons, 2 potentiomètres, 1 LED)
-2 tableaux pour contenir et préparer les messages à afficher sur la première et deuxième ligne.
-4 pour contenir les mesures faites et 4 autres servant de mémoire pour ces mesures.
-1variable contenant le temps écoulé et une servant à savoir sur quelle "interface" noussommes en train d’écrire.

# 0.5.2  Setup
Le setup n’aura que peu de choses à faire puisqu’il suffira de régler les broches en entrées/-sorties et de mettre en marche l’écran LCD

# 0.5.3  recupererDonnees 
elles sera chargée de faire le relevé des valeurs. Son objectif sera de faire les conversionsanalogiques et de regarder l’état des entrées numériques. Elle stockera bien entendu chacune desmesures dans la variable concernée.
0.5.6  La boucle principaleelle est relativement légère, grâce aux fonctions permettant de repartir le code en unitélogique. La boucle principale n’a plus qu’à les utiliser à bon escient et dans le bon ordre pourfaire son travail. Dans l’ordre il nous faudra donc :-Récupérer toutes les données (faire les conversions, etc.).-Selon l’interface courante, afficher soit les états des boutons soit les valeurs des potentio-mètres si ils/elles ont changé(e)s.-Tester les valeurs des potentiomètres pour déclencher l’alarme ou non.-si 5 secondes se sont écoulées, changer d’interface et mettre à jour l’écran.
# 0.5.4  boutonsChanged() et potarChanged()
Ces deux fonctions vont nous permettre de déterminer si oui ou non il faut mettre à jourl’écran. En effet, afin d’éviter un phénomène de scintillement qui se produit si on envoi des don-nées sans arrêt, on préfère écrire sur l’écran que si nécessaire. Pour décider si l’on doit mettre àjour les "phrases" concernant les boutons, il suffit de vérifier l’état "ancien" et l’état courant dechaque bouton. Si l’état est différent, notre fonction renvoie true, sinon elle renvoie false. Unemême fonction sera codée pour les valeurs analogiques. Cependant, comme les valeurs lues parle convertisseur de la carte Arduino ne sont pas toujours très stables (je rappelle que le conver-tisseur offre plus ou moins deux bits de précision, soit 20mV de précision totale), on va faire unepetite opération. Cette opération consiste à regarder si la valeur absolue de la différence entrela valeur courante et la valeur ancienne est supérieure à deux unités. Si c’est le cas, on renvoitrue, sinon false.

# 0.5.5  updateEcran()
Une dernière fonction nous servira à faire la mise à jour de l’écran. Elle va préparer les deuxchaines de caractères (celle du haut et celle du bas) et va ensuite les envoyer successivementsur l’écran. Pour écrire dans les chaines, on vérifiera la valeur de la variable ecran pour savoirsi on doit écrire les valeurs des potentiomètres ou celles des boutons. L’envoi à l’écran se faitsimplement avec print(). On notera le clear() de l’écran avant de faire les mises à jour. En effet,sans cela les valeurs pourraient se chevaucher (si on écrit un on OFF puis un ON sans clear()cela affichera un ONF)
 
# 0.5.6  La boucle principale
elle est relativement légère, grâce aux fonctions permettant de repartir le code en unitélogique. La boucle principale n’a plus qu’à les utiliser à bon escient et dans le bon ordre pourfaire son travail. Dans l’ordre il nous faudra donc :-Récupérer toutes les données (faire les conversions, etc.).-Selon l’interface courante, afficher soit les états des boutons soit les valeurs des potentio-mètres si ils/elles ont changé(e)s.-Tester les valeurs des potentiomètres pour déclencher l’alarme ou non.-si 5 secondes se sont écoulées, changer d’interface et mettre à jour l’écran. 

