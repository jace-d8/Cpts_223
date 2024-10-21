#include <map>
#include "generateUsers.hpp"
using namespace std;


map<string, User> buildMapByUserName(vector<User> users) {
    map<string, User> usersMap;
    for (const auto& user : users)
    {
        usersMap.insert({user.userName, user});
    }
    return usersMap;
}


map<string, User> buildMapByEmail(vector<User> users) {
    map<string, User> usersMap;
    for( auto user : users )
    {
        usersMap.insert({user.email, user});
    }
    return usersMap;
}


void printMap(map<string, User> aMap) {
    for(const auto& items : aMap)
    {
        cout << "Key: " << items.first;
    }
}


bool isMapSorted(map<string, User> aMap)
{
    if ( aMap.empty() )
        return true;
    auto first = aMap.begin();
    auto next = ++first;
    for(; next != aMap.end(); ++first, ++next)
    {
        if(first->second.userName > next->second.userName)
        {
            return false;
        }
    }
    return true;
}

bool testSearchByKey(map<string, User> aMap, string keyToSearch) {
    if(aMap.count(keyToSearch))
    {
        return true;
    }
    return false;
}

bool testDeleteByKey(map<string, User> aMap, string keyToDelete) {
    if(!aMap.count(keyToDelete))
    {
        return false;
    }
    aMap.erase(keyToDelete);
    return true;
}

void printActiveUsers(map<string, User> aMap) {
    int activeThreshold = 800;
    for(const auto& user : aMap)
    {
        if(user.second.numPosts > activeThreshold)
        {
            cout << user.second.userName; // Instead of .first in case email is used as key
        }
    }
}

void printMostPopularCategory(map<string, User> aMap)
{
    map<string, int> catagoryViews = {
        {"Technology", 0},
        {"Sports", 0},
        {"Music", 0},
        {"Food", 0},
        {"Travel", 0},
        {"Education", 0}
    };
    for(const auto& items : aMap)
    {
        catagoryViews[items.second.mostViewedCategory]++;
    }
    int mostViewed = 0;
    string topCategory;
    for(const auto& items : catagoryViews)
    {
        if(mostViewed < items.second)
        {
            mostViewed = items.second;
            topCategory = items.first;
        }
    }
    cout << "Most popular category: " << topCategory;
}


int main()
{
    int numUsers = 10;
    vector<User> users = generateUsers(numUsers);

    cout << "Build map with username as key" << endl;
    map<string, User> mapByUserName = buildMapByUserName(users);
    if ( mapByUserName.size() == numUsers )
        cout << "  Built successfully." << endl << endl;
    else
        cout << "  Built unsuccessfully." << endl << endl;


    cout << "Print \"mapByUserName\" map:" << endl;
    printMap(mapByUserName);
    cout << endl;


    string keyToSearch = "smith55";
    cout << "Search by key: mapByUserName[\"" << keyToSearch << "\"]" << endl;
    if ( testSearchByKey(mapByUserName, keyToSearch) )
        cout << "  Search successfully." << endl << endl;
    else
        cout << "  Search unsuccessfully." << endl << endl;


    string keyToDelete = "smith55";
    cout << "Delete by key: \"" << keyToDelete << "\"" << endl;
    if ( testDeleteByKey(mapByUserName, keyToDelete) )
        cout << "  Delete successfully." << endl << endl;
    else
        cout << "  Delete unsuccessfully." << endl << endl;


    cout << "Test if map's key is sorted" << endl;
    if ( isMapSorted(mapByUserName) )
        cout << "  Order test passed!" << endl << endl;
    else
        cout << "  Order test failed!" << endl << endl;


    cout << "Print usernames with more than 800 tweets:" << endl;
    printActiveUsers(mapByUserName);
    cout << endl;

    cout << "Print the most popular category" << endl;
    printMostPopularCategory(mapByUserName);
    cout << endl;

    cout << " ============================================================================== " << endl << endl;

    cout << "Build map with username as key" << endl;
    map<string, User> mapByEmail = buildMapByEmail(users);
    if ( mapByEmail.size() == numUsers )
        cout << "  Built successfully." << endl << endl;
    else
        cout << "  Built unsuccessfully." << endl << endl;
    
    keyToSearch = "kat@gmail.com";
    cout << "Search by key: mapByEmail[\"" << keyToSearch << "\"]" << endl;
    if ( testSearchByKey(mapByEmail, keyToSearch) )
        cout << "  Search successfully." << endl << endl;
    else
        cout << "  Search unsuccessfully." << endl << endl;


    keyToDelete = "kat@gmail.com";
    cout << "Delete by key: \"" << keyToDelete << "\"" << endl;
    if ( testDeleteByKey(mapByEmail, keyToDelete) )
        cout << "  Delete successfully." << endl << endl;
    else
        cout << "  Delete unsuccessfully." << endl << endl;

    return 0;
}