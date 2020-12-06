///Jorge Rivera shopping list (vectors)
///Created on December 1,2020       
// Dr. Tyson/Tarrant County Community College
//The purpose of this assigment was to create a shopiing list using vectors
//Learned how to use vectors as well as using push back and pop back functions to manipulate vectors
#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std; 

struct shoppingList
{
  string name;
  string desc; 
  char addLetter; 
  char removeLetter;

};

//function definitions
void populatePresent(vector<shoppingList> &entirePresent)
{
  //put some default values in our Present
  const int numItems = 5; 
  shoppingList Item1; 
  shoppingList Item2;
  shoppingList Item3; 
  shoppingList Item4;
  shoppingList Item5;
   
  entirePresent.push_back(Item1); 
  entirePresent.push_back(Item2); 
  entirePresent.push_back(Item3); 
  entirePresent.push_back(Item4); 
  entirePresent.push_back(Item5); 

  vector<string> defaultPresentNames = {"Noise cancelling headphones", "Playstation 5", "RTX3080", "Digital photo frame", "milk"}; 
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E'}; 
 
  for(int i = 0; i < numItems; i++)
  {
    //add each item to the default list efficiently 
    entirePresent[i].name = defaultPresentNames[i]; 
    entirePresent[i].addLetter = defaultAddLetters[i]; 
    entirePresent[3].desc = "    ****Mom's christmas gift!!Dont' forget"; 
  }
}
void showPresent(vector<shoppingList> &m)
{
  cout << "Christmas shopping list" << endl; 
  for(int i = 0; i < m.size(); i++)
  {
    cout << m[i].addLetter << ")" << setw(4) << m[i].name 
    << setw(5) << m[i].desc 
    <<endl; 
  }
}
void acceptOrder(vector<shoppingList> &m)
{
  char option = '\0';
  string line;
  do
  {
    cout << "\nPlease type end to close list(end to Exit): ";

    for(int i=0; i < m.size(); i++)
    {
      cin>>line;
          if (line == "end") 
    {
       cout << "\nChristmas shopping list closed" << endl; 
        exit(0);

    }
              if(i == 0)
              {
                cout << "\nInvalid input (" << option << "). Please try again." << endl; 
              }  
            
     
    }
  }while(option != 'x' && option != 'X'); 

}
int main() 
{
  vector<shoppingList> wholePresent; 
  populatePresent(wholePresent); //put some default values in the Present
  showPresent(wholePresent); //print the current data of the Present on screen 
  acceptOrder(wholePresent); 
  
  return 0; 
}