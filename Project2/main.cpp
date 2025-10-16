#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    // Reading text from file
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cout << "Failed to open input.txt!" << endl;
        return 1;
    }

    string word;
    map<string, int> arr; // word -> number of repetitions

    // Counting how many times each word appears
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

    // Finding the most frequent word
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

    // Writing results to file
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