#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <io.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
//Metindeki ulamayı bulan fonksiyon
int connexionFinder(char *text)
{
    int i = 0;
    char *consonantArray = {"zyvtþsrpnrmlkhjğgdçcbZYVTÞSRPNRMLKHJĞGDÇCB"};
    char *vowelArray = {"aeıioöuüAEIİOÖUÜ"};
    int connexionCount = 0;
    int wordIndex = 0, wordInIndex = 0;
    char words[100][50];

    while (text[i + 2] != '\0') {
        if ((strchr(consonantArray, text[i]) != NULL) && (text[i + 1] == ' ') && (strchr(vowelArray, text[i + 2]) != NULL))
            {
            connexionCount++;
            }
            i++;
    }
    return connexionCount;
}
//connexionFinder fonksiyonunun bulduğu kelimeleri yazdıran void fonksiyon
void printConnexions(const char *text){
    int i = 0;
    char *consonantArray = {"zyvtşsrpnrmlkhjğgdçcbZYVTŞSRPNRMLKHJĞGDÇCB"};
    char *vowelArray = {"aeıioöuüAEIİOÖUÜ"};
    int connexionCount = 0;
    int wordIndex = 0, wordInIndex = 0;
    char words[15][50];

    //Ulama sayısını bulma
    while(text[i+2] != '\0'){
        if((strchr(consonantArray,text[i]) != NULL) && (text[i+1] == ' ') && (strchr(vowelArray,text[i+2]) != NULL)){
            connexionCount++;
            int temp = i;
            int endpoint;
            int connexionPoint = i;

            //Ulamaları yazdırma
            //Bir bağlantı oluştuğunda aşağıdaki while döngüsü, bağlantının mevcut olduğu dizinden kelimenin ilk dizinine geri döner
            while (1) {
                i--;
                if(text[i-1] == ' ' || text[i-1] == '\0')
                    break;

            }
            //Bir bağlantı oluştuğunda aşağıdaki while döngüsü, bağlantının bulunduğu dizinden kelimenin son dizinine doğru sonuna kadar gider
            while (1) {
                connexionPoint++;
                if(text[connexionPoint + 1] == ' ' || text[connexionPoint + 1] == '\0')
                    break;

            }
            //Sonra bu iki kelimeyi birleştirme
            int startPoint = i;
            endpoint = connexionPoint;
            for (i = startPoint; i <= endpoint; ++i) {
                words[wordIndex][wordInIndex] = text[i];
                wordInIndex++;

            }
            wordIndex++;
            wordInIndex = 0;
            i = temp;
        }
        i++;
    }

    //Kelimeleri yazdırma
    for (int j = 0; j < wordIndex; ++j) {
        printf("%s, ", words[j]);
    }
}
//Küçük ünlü uyumunu bulan fonksiyon
int littleVowelHarmony(char *text)
{
    int length;
    int i,j;
    int letter1=0;
    int letter2=0;
    int letter3=0;

    length=strlen(text);
//Aşagıdaki for döngüsü küçük ünlü uyumu kurallarına göre kelimeleri inceler
    for(i=0;i<length;i++)
    {
        if(text[i]=='a'||text[i]=='e'||text[i]=='ı'||text[i]=='i')
        {
            j=i+1;
            for(j;j<length;j++)
            {
                if(text[j]=='a'||text[j]=='e'||text[j]=='ı'||text[j]=='i')
                {
                    letter1++;
                }
                else if(text[j]=='o'||text[j]=='ö'||text[j]=='u'||text[j]=='ü')
                {
                    letter3++;
                }

            }
            break;
        }
        if(text[i]=='o'||text[i]=='ö'||text[i]=='u'||text[i]=='ü')
        {
            j=i+1;
            for(j;j<length;j++)
            {
                if(text[j]=='a'||text[j]=='e'||text[j]=='u'||text[j]=='ü')
                {
                    letter2++;
                }
                else if(text[j]=='o'||text[j]=='ö'||text[j]=='ı'||text[j]=='i')
                {
                    letter3++;
                }
            }
            break;
        }
    }
//Kurallara uygun olarak kelimeleri yazdırma
    if (letter1>0 && letter3==0)
    {
        printf("%s, ",text);
    }
    else if (letter2>0 && letter3==0)
    {
        printf("%s, ",text);
    }

    return 0;
}
//Büyük ünlü uyumunu bulan fonksiyon
void greatVowelHarmony(char *text)
{
    int length;
    int i;
    int thick=0;
    int thin=0;

    length=strlen(text);
//Aşagidaki for döngüsü büyük ünlü uyumu kurallarına göre kelimeleri inceler
    for(i=0;i<length;i++)
    {
        if(text[i]=='a'||text[i]=='o'||text[i]=='u'||text[i]=='ı')
        {
            thick++;
        }
        if(text[i]=='e'||text[i]=='i'||text[i]=='ü'||text[i]=='ö')
        {
            thin++;
        }

    }
//Kurallara uygun olarak yazdırma
    if(thick==0||thin==0)
    {
        printf("%s, ",text);
    }

}
//Yumuşak ünlüleri bulan fonskiyon
int softVowelFinder(char *text)
{
    char *softLetter ="bcdgğjlmnrvyz";
    int softVowel=0;
    int i=0;
//Aşagidaki while döngüsü metinin sonu gelene kadar dizide tanımlanmış karakterlerin girilen metinde olup olmadıgını kontrol eder
    while(text[i] != '\0')
    {
        if((strchr(softLetter,(int)text[i])!=NULL))
            softVowel++;
            i++;

    }

    return softVowel;
}
//Sert ünlüleri bulan fonksiyon
int strongVowelFinder(char *text)
{
    char *strongLetter ="fstkçþhp";
    int strongVowel=0;
    int i=0;
//Aşagidaki while döngüsü metnin sonu gelene kadar dizide tanımlanmış karakterlerin girilen metinde olup olmadıgını kontrol eder
    while(text[i] != '\0')
    {
        if((strchr(strongLetter,(int)text[i])!=NULL))
            strongVowel++;
        i++;
    }

    return strongVowel;
}
//Çogul kelimeleri bulan fonksiyon
int pluralWordFinder(char *text)
{
    int i=0;
    int plural=0;
//Aşagidaki while döngüsü metin bitene kadar döngüye devam eder
    while(text[i] != '\0')
    {
        if(text[i]=='l' && text[i+1]=='a' && text[i+2]=='r')
        {
            plural=1;
        }
        if(text[i]=='l' && text[i+1]=='e' && text[i+2]=='r')
        {
            plural=1;
        }
        i++;

    }

    return plural;
}
//Kelime sayısını bulan fonksiyon
int  wordCountFinder(char *text)
{
    int i=0;
    int wordCount=0;
    while (text[i]!='\0') {
        if(text[i]==' ')
            wordCount++;
        i++;
    }
    return wordCount+1;
}
//Cümle sayısını bulan fonksiyon
int sentenceFinder(char *text)
{
    int i=0;
    int sentence=0;
    while (text[i]!='\0')
    {
        if(text[i]=='.'||text[i]=='!'||text[i]=='?')
            sentence++;
        i++;
    }
    return sentence+1;
}
//Noktalama işaretleri bulan fonksiyon
int dotFinder(char *text)
{
    int i=0;
    int dot=0;
    while (text[i]!='\0')
    {
        if(text[i]=='.'||text[i]=='!'||text[i]=='?')
            dot++;
        i++;
    }
    return dot+1;
}
//Main başlangıcı
int main()
{
//Türkçe karakterlerin çalışması için girilen kod

    SetConsoleCP(1254);
    SetConsoleOutputCP(1254);
    setlocale(LC_ALL,"Turkish");
//Değişken tanımları
    int choise;
    int wordCount=0;
    int sentence=0;
    int dot=0;
    int letter=0;
    int connexion=0;
    int i;
    int thin=0;
    int thick=0;
    int plural=0;
    char text[10000];
    char *wordArray[1000];
    char holdText[10000]; // text dizisini kopyalamak icin acilan dizi
    char *pluralWords[1000];
    printf("<***> TURKISH GRAMMAR DETECTION <***> ");
//Kullanıcıdan metin girmesi istenir

    puts("\nEnter a text = ");
    gets(text);

//text dizisini holdtext dizisine kopyalama
    strcpy(holdText,text);
    char *result = strtok( holdText, " " );
    int j = 0;

//Girilen metindeki kelimeleri ayırıp yeni bir diziye atama
	while( result != NULL )
	{
	    wordArray[j] = result;
	    result = strtok(NULL," ");
	    j++;
	}

//PluralWords dizisinin içine çoğul olan kelimeleri atma
    for(int i = 0; i < j ; i++)
    {
        if (pluralWordFinder(wordArray[i]) == 1)
        {
            pluralWords[plural] = wordArray[i];
            plural++;
        }

    }
//Menüyü döngüye alarak kullanıcıya birden fazla işlem sonucu gösterilebilir.
    while(1)
    {



        printf("\n0.Exit");
        printf("\n1.Connexion");
        printf("\n2.Great Vowel Harmony");
        printf("\n3.Little Vowel Harmony");
        printf("\n4.Soft Vowels");
        printf("\n5.Strong Vowels");
        printf("\n6.Plural Words");
        printf("\n7.Number of Words");
        printf("\n8.Number of Sentences");
        printf("\n9.Number of Letters");

        printf("\nPlease select the action you want to take = ");
        scanf("%d",&choise);
        if(choise==0)
        {
            printf("EXIT");
            break;
        }
        else if(choise==1)
        {
            connexion=connexionFinder(text);
            printf("Number of connexion = %d\n",connexion);

            printConnexions(text);

        }

        else if(choise==2)
        {
            printf("Uyanlar: ");
            for(int i = 0; i < j ; i++)
            {
                greatVowelHarmony(wordArray[i]);

            }

        }

        else if(choise==3)
        {
                printf("Uyanlar: ");

            for(int i = 0; i < j ; i++)
            {
                littleVowelHarmony(wordArray[i]);
            }

        }

        else if(choise==4)
        {
            printf("Number of soft vowel = %d\n",softVowelFinder(text));

        }
        else if(choise==5)
        {
            printf("Number of strong vowel = %d\n",strongVowelFinder(text));

        }

        else if(choise==6)
        {
            printf("Number of plural words = %d\n",plural);
            for (int i = 0; i < plural ; i++)
            {
                printf("%s, ",pluralWords[i]);
            }

        }

        else if(choise==7)
        {
            wordCount=wordCountFinder(text);

            printf("The text you entered consists of %d words.", wordCount);
        }

        else if(choise==8)
        {
            sentence=sentenceFinder(text);

            printf("The text you entered consists of %d sentence.", sentence-1);
        }
        else if(choise==9)
        {
            letter=strlen(text);

            wordCount=wordCountFinder(text);
            dot=dotFinder(text);

            printf("The text you entered consists of %d words.", ((letter-wordCount-dot)+2));

        }

        else
            printf("Please enter a valid value !!!");
    }

    return 0;
}
