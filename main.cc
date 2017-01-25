#include "Web.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(){
  system("clear");
  while(1){
    Web<int> web;
    string val;
    string ans;
    int num;
    cout << "What would you like to do?\n-ENTER-Add Elements\n-2-Exit" << endl;
    getline(cin,val); 
    if(val == "2") {system("clear");break;};
    cout << "How many elements to add?\n";
    cin >> num;
    clock_t init,final;
    system("clear"); 
    cout << "--------------------Starting Testing--------------------" << endl;
    int toAdd = num;
    init = clock();
    srand(time(NULL));
    for(int i = 0; i <= toAdd; i++){
      web.addNode(rand()%100);
    }
    final = clock()-init;
    cout << "\nTime: Added : " << toAdd 
    << " elements in " << (double)final / ((double)CLOCKS_PER_SEC)
    << " seconds" << endl;
  
    cout << "\nThe size of the web is : " << web.getSize()-1 << endl;
    cin.clear();
    cin.ignore();
    cout << "Print Contents?(y/n)\n";
    getline(cin,ans);
    if(ans == "y" || ans == "Y"){ 
      web.displayContents();
    }
    cout << "\n\n";
    cin.clear();
    cout << "Would you like to search for an Element?(y/n)\n";
    getline(cin,val);
    if(val == "y" || val == "Y"){
      while(val == "Y" || val == "y"){
        int src;
        cout << "What would you like to search for?(-1 means not found)\n";
        cin >> src;
        cout << "Found at key " << web.getPos(src) << endl;
        cin.ignore();
        cin.clear();
        cout << "Search again?(y/n)\n";
        getline(cin,val);
      }
    }
  }
  return 0;
}