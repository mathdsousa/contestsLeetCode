#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> novalista(vector<char> &lista, int posicao) // Function for new substring
{
    vector<char> nova;
    int i = posicao + 1;
    int j = 0;
    while(i != lista.size()){nova.push_back(lista[i++]); j++;};

    return nova;
}

int lengthOfLongestSubstring(string s) {
    vector<char> lista; // store the current substring caracters without repetition
    bool repetiu = false; // character repeat flag
    int posicao = -1; // stores the position od the occurrence of the letter on the current substring
    int maior = 0; // stores the lenght of major substring without repetition character

    for(int i = 0; i < s.size(); i++) // compare each letter of the given string 
    {                                 // with each letter of current substring
        for(int j = 0; j < lista.size(); j++)
            if(s[i] == lista[j]) // if the letter is already in the substring
            {
                repetiu = true; // indicates that there was repetition
                posicao = j; // store the position of repeated letter in the substring 
                break;
            }
        if(repetiu)
        {
            lista = novalista(lista, posicao); // eliminates the repeated letter and the characteres before it from the substring
            repetiu = false; // sets the flag
        }
        lista.push_back(s[i]); // adds the current letter in the new substring
        if(lista.size() > maior) // checks if the lenght of the new substring is greater than 
            maior = lista.size(); // the largest substring ever found
    }

    return maior;    
}

int main()
{
    string s;
    cout << "Digite uma palavra: ";
    cin >> s;
    cout << endl;

    cout << "O tamanho da maior substring é " << lengthOfLongestSubstring(s) << endl;

    return 0;
}