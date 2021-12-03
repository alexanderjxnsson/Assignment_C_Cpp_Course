Skapade:        Alexander Jönsson
Projekttyp:     Final assignment for C/C++ programming
Krav:           OS Windows & keyboard
Jag använde:    Visual Studio Code w/ g++ & g++ 14 standard

I början tänkte jag att det skulkle bli omständigt att behöva göra ett helt nytt program bara någon vecka innan inlämning.
Jag började lite smått med ATM som slutuppgift men var fortfarande inte helt bekväm med filläsande/skrivande. Så jag gav upp
den idén ganska snabbt och bestämde mig för att börja från scratch. Vilket jag nu är glad över att jag gjorde.
Känner att jag fick rätt på både filskrivandet/läsandet samt läsa in det till en vector etc.
Så det var både utmanande och lärorikt. Samt att jag hade problem när jag skulle skapa ny fil, läsa över, ta bort gamla och byta namn.
Satt i dagar och till slut fick jag börja läsa min kod från början och hittade problemet direkt.. Jag stängde inte filen när jag kollade om den var ok, lesson learned.

Programmet består utav 3 filer + .csv, main.cpp, functions.h, declarations.h. Programmet börjar i main.cpp, där kollar vi så att filen är OK samt lägger in allt i en vector som är kopplad till en struct.
Är filen OK aktiverar vi bMenuRunning-boolen som tillåter oss att loopa i mainMenu-functionen. Är filen inte OK sätter vi bMenuRunning till false, samt stänger programmet.

Bra att veta:
- Admins lösenord är en konstant satt till 666.
- Variabeln sleepTime är satt till 2250, den går att öka för att hinna med att läsa vad som kommer upp innan skärmen töms.

Funktionerna förklarade:

void fileChecking()
{
    Vi öppnar filen, sen med en if-sats kollar vi ifall den är öppen, är den öppen fortsätter vi programmet samt stänger filen igen, är den inte öppen stänger vi hela programmet.
}

void welcomeHeader/ingameHeader/adminHeader/highscoreHeader/columnBanner()
{
    Dessa funktionerna innehåller headers utav iomanip för olika menyer i spelet.
}

void ingameTable()
{
    Denna funktionen visar spelarens poäng samt antal försök under spelets gång.
}

void showHighscoreList()
{
    Här läser vi in csv-filen igen, tömmer vår vector och läser in all information frånm filen till vectorn.
    Sen med hjälp utav iomanip får vi ut informationen snyggt i kolumner.
}

void mainMenu()
{
    Skriver ut de olika valen för mainMenu-funktionen.
}

void mainMenu()
{
    Här ligger huvudmenyn, där alternativen "Play", "See highscore list", "Enter admin mode" eller "Exit" ligger i en switch.
    - Play skickar oss till theGame-funktionen.
    - Highscore skicka oss till showHighscoreList, med två olika funktioner för headers.
    - Admin, så kommer vi till adminmenyerna.
    - Exit avslutar spelet.
    - Finns en default för att fånga upp fel var av meny.
}

int randomizer(int a)
{
    Har kastar vi in variabeln winningNumber som sedan blir returnerat som en slumpad siffra mellan 1 och 10.
}

void theGame()
{
    Här är själva spelet! Vi börjar med att nollställa alla variabler som används, visar ingameHeader och ber spelaren skriva in namn och hemstad, sen tömmer vi skärmen och visar två andra header/table-funktioner. Vi slumpar även försa siffran.

    Sen är det fritt fram för spelaren att gissa. Gissar personen rätt avläser vi det via en if-sats. Vi adderar +1 på två gissningsvariabler samt kastar in antal försök i settingTheScore-funktionen som returnar ett visst antal poäng beroende på antal gissningar den rundan. Spelaren kan välja att fortsätta spela för att öka sina poäng, eller att avsluta och då skicka in sina poäng och gissningar i csv-filen.

    Gissar spelaren fel, lägger vi till +1 på gissningsvariablerna igen, samt skickar in siffran spelaren gissade på i en array som sedan skriver ut en gissningshistorik. Vi kollar även ifall siffran var lägre eller högre än vad de slumpade numret är.

    Gissar spelaren fel 5 gånger avslutas spelet och personens försök samt poäng sparas i csv-filen.
}

int settingTheScore(int tries)
{
    Här kastar vi in antal försök från spelaren under spelets gång i theGame-funktionen när personen gissat rätt.
    Sen kör vi igenom antal försök i en if-sats och betstämmer antal poäng och returnerar det värdet, som vi sen sparar i personen poängvariabel.
}

void adminMode()
{
    Här börjar admin-menyn. Först kör vi en loop där personen får logga in, skriver personen rätt lösenord kommer vi vidare till admins huvudmeny.
    Skriver personen fel tre gånger kastas vi ut ur adminMode().

    Väl inne i huvud menyn finns det tre val, ta bort specifik spelare från listan, tömma hela listan eller logga ut ur adminmenyn.

    Väljer användaren att ta bort en specifik person från listan fåpr användaren skriva in namnet som vi sedan skickar in i adminDeletePlayer, förklarar den längre ner. Användaren kan också skriva 'cancel' för att avbryta.

    Vill personen tömma hela listan går vi in i emptyhighscoreList, förklarar även den längre ner.

    Sista valet är att avsluta adminmenyn.
}

void adminDeletePlayer(std::string playerName)
{
    I denna funktioen öppna vi nuvarande csv-filen, samt skapar och öppnar en ny fil. Vi går igenom den gamla filen och letar upp namnet i listan, sen skriver vi in alla andra användare i nya csv-filen. När vi gått igenom hela gamla filen, stänger vi båda och tar bort den gamla, samt döper om den nya till det gamla namnet.
}

void emptyHighscoreList()
{
    I denna funktioen får vi valet om vi vill tömma hela listan eller inte. Väljer vi ja, tömmer vi den med trunc.
    Väljer vi nej, hoppar vi ur menyn igen.
}