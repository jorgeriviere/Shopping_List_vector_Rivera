#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std; 
class MenuItem
{
private:
  double itemCost;
  char addLetter;
  char removeLetter;
  int count;
    string name;
  string desc;
public:
  void setName(string);
  void desc(string);
  void setitemCost(double);
  void setaddLetter(char);
  void setremoveLetter(char);
  void setcount(int);
  double getitemCost() const;
  char setaddLetter() const;
  char setremoveLetter() const;
  int getcount() const;
};
///Sets
void setName (string n)
  {
    name = n;
  }
  void desc(string d)
  {
    desc = d;
  }
void MenuItem::setitemCost(double c)
{
  itemCost=c;
}
void MenuItem::setaddLetter(char a)
{
  addLetter=a;
}
void MenuItem::setremoveLetter(char r)
{
  removeLetter=r;
}
void MenuItem::setcount(char t)
{
  count=t;
}
///GETS

double MenuItem::getitemCost()const
{
  return itemCost;
}
char MenuItem::getaddLetter()const
{
  return addLetter;
}
char MenuItem::getremoveLetter()const
{
  return removeLetter;
}
int MenuItem::getcount ()const
{
  return count;
}
//function definitions
void populateMenu(vector<MenuItem> &entireMenu)
{
  //put some default values in our Menu
  const int numItems = 7; 
  MenuItem Item1; 
  MenuItem Item2;
  MenuItem Item3; 
  MenuItem Item4;
  MenuItem Item5;
  MenuItem Item6;
  MenuItem Item7;    

  entireMenu.push_back(Item1); //add to the end of list the Item1
  entireMenu.push_back(Item2); //add to the end of list the Item2
  entireMenu.push_back(Item3); //add to the end of list the Item3
  entireMenu.push_back(Item4); //add to the end of list the Item4
  entireMenu.push_back(Item5); //add to the end of list the Item5
  entireMenu.push_back(Item6); //add to the end of list the Item6
  entireMenu.push_back(Item7); //add to the end of list the Item7

  vector<string> defaultMenuNames = {"Green Tea", "Burrito", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7"}; 
  vector<char> defaultAddLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G'}; 
  vector<char> defaultRemoveLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; 

  for(int i = 0; i < numItems; i++)
  {
    //add each item to the default list efficiently 
    entireMenu[i].getname = defaultMenuNames[i]; 
    entireMenu[i].getaddLetter = defaultAddLetters[i]; 
    entireMenu[i].getremoveLetter = defaultRemoveLetters[i]; 
    entireMenu[i].getitemCost = (3.00 + i); //set a random starter cost for each item
    entireMenu[i].getcount = 0; //initialze all counts to 0
    entireMenu[i].getdesc = "delicious"; //set all default desc to "delicous"
  }


}

void showMenu(vector<MenuItem> &m)
{
  cout << fixed << setprecision(2);//set doubles to 2 decimal places
  cout << "DrT's Effcient Menu" << endl; 
  cout << "ADD  \tNAME \t COST \tREMOVE\tCOUNT\tDESC"<<endl; 
  for(int i = 0; i < m.size(); i++)
  {
    cout << m[i].setaddLetter << ")" << setw(10) << m[i].setname 
    << setw(5) << "$" << m[i].setitemCost << setw(5) << "(" << m[i].setremoveLetter
    << ")" << setw(7) << m[i].setcount << setw(13) << m[i].setdesc 
    <<endl; 
  }

}

void acceptOrder(vector<MenuItem> &m)
{
  char option = '\0';// the user-selected menu item
  double subtotal = 0.0; 

  do
  {
    cout << "\nPlease choose an item (x to Exit): ";
    cin >> option; 

    for(int i=0; i < m.size(); i++)
    {
      if(option == m[i].addLetter)
      {
        cout << "\nMenu Item " << m[i].addLetter << " selected."; 
        m[i].count++; //increment the count by 1
        cout << "\033[2J\033[1;1H"; //clear screen 
        cout << "\n1 UP on " << m[i].name << endl;
        subtotal += m[i].itemCost; //increment the subtotal by the cost of the item 
        showMenu(m); //show the updated menu
        cout << "\nSubtotal: $" << subtotal << endl;  
      }
      else if(option == m[i].removeLetter)
      {
        cout << "\nRemove Item " << m[i].removeLetter << " selected."; 
        if(m[i].count > 0) //subtract if and only if the count is > 0
        {
          m[i].count--; //decrement the count by 1
          cout << "\033[2J\033[1;1H"; //clear screen 
          cout << "\n1 DOWN on " << m[i].name << endl;
          subtotal -= m[i].itemCost; //decrement the subtotal by the cost of the item
          showMenu(m); //show the updated menu
          cout << "\nSubtotal: $" << subtotal << endl;  
        }
        else //the the user why you blocked item removal 
        {
            
            cout << "\nItem count must be > 0 to remove: " << m[i].name << endl;
        }
      }
      else if(
                option != m[i].addLetter && 
                option != m[i].removeLetter &&
                option != 'x' &&
                option != 'X' 
            ) //test for all of my valid inputs
            {
              if(i == 0)
              {
                cout << "\nInvalid input (" << option << "). Please try again." << endl; 
              }  
            }
    }
  }while(option != 'x' && option != 'X'); 
  cout << "\nThank you for placing your order." << endl; 
  //handle the tip process here
  //handle reciept generation here
}

int main() 
{
  vector<MenuItem> wholeMenu; 
  populateMenu(wholeMenu); //put some default values in the menu
  showMenu(wholeMenu); //print the current data of the menu on screen 
  acceptOrder(wholeMenu); 
  
  return 0; 
}