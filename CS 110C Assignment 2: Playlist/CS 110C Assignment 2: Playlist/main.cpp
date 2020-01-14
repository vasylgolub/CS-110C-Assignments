// Array-based List Class for Playlists
// Max Luttrell CS 110C
// Golub Vasyl

#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;




template<class ItemType>
class List
{
private:
    static const int CHUNK_SIZE=4;

    ItemType *list;
    int numItems;
    int maxItems;
    
    void makeTheListLarger();//Problem number 3.
public:
    
    // default constructor and destructor
    List() {    numItems = 0;
                maxItems = CHUNK_SIZE;
                list = new ItemType[CHUNK_SIZE];
            }
//    void howManyItems(){cout<<numItems<<endl;}
    ~List() { delete [] list; }
    
    // list member functions
    bool isEmpty() { return numItems==0; }
    int getLength() { return numItems; }
    bool insert(int pos, const ItemType& item);
    bool remove(int pos);
    
    // clear can simply set numItems to zero.  The array list may still contain
    // items already inserted into the list, but since numItems is zero, there
    // isn't any way to get at them using getEntry() or setEntry()
    void clear() { numItems = 0; }
    
    // throw invalid_argument if pos<1 or pos>getLength()
    ItemType getEntry(int pos) const throw(invalid_argument);
    
    // throw invalid_argument if pos<1 or pos>getLength()
    void setEntry(int pos, const ItemType& item) throw(invalid_argument);
};






//```````````````````````````````````makeListLarger````````````````````````````````````````````````
template<class ItemType>
void List<ItemType>::makeTheListLarger(){
    int newMaxItems = maxItems * 2;
    
    ItemType *copyList = new ItemType[maxItems];
    
    //copy old list to the new list with the same size
    for (int i = 0; i<maxItems; i++) {
        copyList[i] = list[i];
    }
    
    delete []list;//delete the items from our original list
    
    
    list = new ItemType[newMaxItems]; //Reallocate memory with bigger size
    
    //return the items to the original list (bigger now) from the copyList previously copied
    for (int i = 0; i<maxItems; i++) {
        list[i] = copyList[i];
    }
    
    delete []copyList;
    copyList = nullptr;
    
    
    maxItems = newMaxItems; //now our max items is bigger 2 times than the privious one.
 
}
//```````````````````````````````````end-makeListLarger````````````````````````````````````````````







//--------------------------------------INSERT-----------------------------------------------
template<class ItemType>
bool List<ItemType>::insert(int pos, const ItemType& item)
{
    bool canAdd;
    
    if (numItems == maxItems) {
        makeTheListLarger();
    }
    
    canAdd = (
              (pos > 0) && (pos <= numItems + 1) && (numItems < maxItems)
             );
    
    if (canAdd)
    {
        //{ first, we have to move everything after our insertion point over one
        // position to make room for our new item.  start at the back of the list.
        // don't forget arrays start at postion zero and our list ADT starts at
        // }position 1.
        for(int i=numItems; i>=pos; i--)
            list[i] = list[i-1];
        
        // now put our item at position pos-1
        list[pos-1] = item;
        
        numItems++;
    }
    
    return canAdd;
}
//--------------------------------------END-INSERT--------------------------------------------









//--------------------------------------GET ENTRY-----------------------------------
template<class ItemType>
ItemType List<ItemType>::getEntry(int pos) const throw(invalid_argument)
{
    if(pos<1 || pos>numItems) {
        throw invalid_argument("ERROR: getEntry() using invalid position");
    }
    return list[pos-1];
}
//--------------------------------------end-GET ENTRY-------------------------------




//--------------------------------------setENTRY------------------------------------------------
template<class ItemType>
void List<ItemType>::setEntry(int pos, const ItemType& item) throw(invalid_argument){
    if (pos<1 or pos>numItems){
        string error = "ERROR! No Item existent in position: " + to_string(pos);
        throw invalid_argument(error);
    }
    
    list[pos-1] = item;
    
}
//--------------------------------------end-setENTRY--------------------------------------------






// Utility function to input a track number with some input checking
// to make sure it's a number/////////////////////////////////////////////////////////////
int getTrack()
{
    bool inputCheck;
    int trackNumber;
    
    do
    {
        inputCheck = true;
        cout << "Please enter the track number you'd like to view: ";
        if (!(cin >> trackNumber))
        {
            cout << "Please enter numbers only.\n";
            cin.clear();
            cin.ignore(10000,'\n');
            inputCheck = false;
        }
    } while (!inputCheck);
    return trackNumber;
}
////////////////////////////////////////////////////////////////////////////////////////////




//__________________________________remove___________________________________________________
template<class ItemType>
bool List<ItemType>::remove(int pos)
{
    bool canRemove = ((pos > 0) && (pos <= numItems ) && (numItems <= maxItems));
    
    if (canRemove)
    {
        for (int i = pos-1; i<numItems-1; i++) {
            list[i] = list[i+1];
        }
       
        numItems--;
    }
    
    return canRemove;
}
//__________________________________end-remove_________________________________________________




template<class ItemType>
List<ItemType> getListFromTwoSortedLists(List<ItemType> first, List<ItemType> second){
    List<ItemType> returnList;
    
    for (int i = 1; i<first.getLength(); i++) {
        if ((first.getEntry(i).compare(second.getEntry(1))) > 1) {
            
        }
    }
    
}

int main()
{
    List<string> firstL;
    firstL.insert(1, "alex");
    firstL.insert(2, "bruce");
    
    
    
    List<string> secondL;
    secondL.insert(1, "erik");
    secondL.insert(2, "frank");
    secondL.insert(3, "greg");
    
    
    
    
    
    
    string s = "frank";
     cout<<s.compare("erik")<<endl;
    cout<<s.compare("frank")<<endl;
    cout<<s.compare("greg")<<endl;
    
    
    return 0;
}






























//
//List<string> songs;
//char goAgain = 'y';
//int trackNumber;
//string trackName;
//// Insert some songs into our list
//songs.insert(1, "One More Saturday Night");
//songs.insert(1, "Friday I'm in Love");
//songs.insert(3, "Sunday Morning Coming Down");
//songs.insert(1, "California Love");
//
//
////output++++++++++++++++++++++++++++++++++++++++
//for (int i = 1; i<=songs.getLength(); i++) {
//    cout<<songs.getEntry(i)<<endl;
//    }
//    cout<<endl;
//    //+++++++++++++++++++++++++++++++++++++++++++++++
//    cout<<"About to remove from the list song: "<<songs.getEntry(3)<<endl<<endl;
//    songs.remove(3);
//    
//    
//    //output++++++++++++++++++++++++++++++++++++++++
//    for (int i = 1; i<=songs.getLength(); i++) {
//        cout<<songs.getEntry(i)<<endl;
//    }
//    cout<<endl;
//    //+++++++++++++++++++++++++++++++++++++++++++++++
//    
//    cout<<"About to remove from the list song: "<<songs.getEntry(1)<<endl<<endl;
//    songs.remove(1);
//    
//    //output++++++++++++++++++++++++++++++++++++++++
//    for (int i = 1; i<=songs.getLength(); i++) {
//        cout<<songs.getEntry(i)<<endl;
//    }
//    cout<<endl;
//    //+++++++++++++++++++++++++++++++++++++++++++++++
//    
//    cout<<"About to change the song in the list at position 1: "<<songs.getEntry(1)<<endl<<endl;
//    songs.setEntry(1, "Everlong");
//    
//    //output++++++++++++++++++++++++++++++++++++++++
//    for (int i = 1; i<=songs.getLength(); i++) {
//        cout<<songs.getEntry(i)<<endl;
//    }
//    cout<<endl;
//    //+++++++++++++++++++++++++++++++++++++++++++++++
//    
//    
//    cout<<"About to change the song in the list at position 3: "<<endl;
//    try {
//        songs.setEntry(3, "Everlong");
//    } catch (invalid_argument arg) {
//        cout<<arg.what()<<endl<<endl;
//    }
//    
//    
//    //output++++++++++++++++++++++++++++++++++++++++
//    for (int i = 1; i<=songs.getLength(); i++) {
//        cout<<songs.getEntry(i)<<endl;
//    }
//    cout<<endl;
//    //+++++++++++++++++++++++++++++++++++++++++++++++
//    
//    songs.insert(1, "Stars");
//    songs.insert(1, "One More Time");
//    cout<<"total songs now, after adding two more, are: "<<songs.getLength()<<endl;
//    //output++++++++++++++++++++++++++++++++++++++++
//    for (int i = 1; i<=songs.getLength(); i++) {
//        cout<<songs.getEntry(i)<<endl;
//    }
//    cout<<endl;
//    //+++++++++++++++++++++++++++++++++++++++++++++++
//    
//    
//    songs.insert(1, "Diamonds");
//    songs.insert(1, "Night Long");
//    cout<<"total songs now, after adding two more, are: "<<songs.getLength()<<endl;
//    //output++++++++++++++++++++++++++++++++++++++++
//    for (int i = 1; i<=songs.getLength(); i++) {
//        cout<<songs.getEntry(i)<<endl;
//    }
//    cout<<endl;
//    //+++++++++++++++++++++++++++++++++++++++++++++++
//    

    
    

