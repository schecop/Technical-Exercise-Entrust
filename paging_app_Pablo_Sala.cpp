#include <iostream>
#include <fstream>          // to open files

using namespace std;

int main()
{
    ifstream doc;
    doc.open("document.txt");                           // open input file to read
    if (!doc)                                           // if it can't be opened, inform and close program
    {
        cout << "Unable to open file" << endl;
        exit(1);
    }
    ofstream doc_paged;                                 // open output file to write
    doc_paged.open("document_paged.txt");
    if (!doc_paged)                                     // if it can't be created, inform and close program
    {
        cout << "Unable to create file" << endl;
        exit(1);
    }

    // we first read the text. As it is only 1 line this function is enough
    string text;
    getline(doc, text);


    int num_chars = 0;              // keep track of the number of characters written in a line
    int num_lines = 0;              // keep track of the number of lines written in a page
    int num_page = 1;               // keep track of the number of pages written

    // go through each character of the text in order to copy it onto the output file as required
    int i=0;
    while(i < text.length())
    {
        doc_paged << text[i];
        num_chars++;

        if (num_chars>=80 && isspace(text[i]))         // if 80 characters have already been written in the line and last character is a whitespace -> new line
        {
            doc_paged << endl;
            num_lines++;
            num_chars=0;
        }

        if (num_lines == 25)                           // if 25 lines have already been written -> add separation mark with page number
        {
            doc_paged << "------------------------------------- PAGE " << num_page << " -------------------------------------" << endl;
            num_lines = 0;
            num_page++;
        }
        
        i++;
    }

    return 0;
}