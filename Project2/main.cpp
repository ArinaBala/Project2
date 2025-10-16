#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

int main()
{
 
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cout << "Failed to open input.txt" << endl;
        return 1;
    }

    string word;
    map<string, int> arr; 

   
    while (fin >> word)
    {
        arr[word]++;
    }

    fin.close();

    cout << "All words and their frequencies:\n";
    for (auto ptr = arr.begin(); ptr != arr.end(); ptr++)
    {
        cout << ptr->first << "\t" << ptr->second << endl;
    }

    cout << "\nWords that appear more than 2 times:\n";
    for (auto ptr = arr.begin(); ptr != arr.end(); ptr++)
    {
        if (ptr->second > 2)
            cout << ptr->first << "\t" << ptr->second << endl;
    }

    
    string mostWord;
    int maxCount = 0;

    for (auto ptr = arr.begin(); ptr != arr.end(); ptr++)
    {
        if (ptr->second > maxCount)
        {
            maxCount = ptr->second;
            mostWord = ptr->first;
        }
    }

    cout << "\nMost frequent word: " << mostWord << " (" << maxCount << " times)" << endl;

  
    ofstream fout("output.txt");
    for (auto ptr = arr.begin(); ptr != arr.end(); ptr++)
    {
        fout << ptr->first << "\t" << ptr->second << endl;
    }

    fout << "\nMost frequent word: " << mostWord << " (" << maxCount << " times)" << endl;
    fout.close();

    cout << "\nResults have been written to output.txt" << endl;

    return 0;
}
