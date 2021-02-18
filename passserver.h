
/* Name: Andrew Stade
Date: 11/23/2020
Section: COP 4530 */

#include "hashtable.h"

using namespace std;
using namespace cop4530;

class PassServer
{
	public:
		PassServer(size_t size = 101);								// constructor, create a hash table of the specified size.
		~PassServer();												// destructor.
		bool load(const char *filename);							// load a password file into the HashTable object.
		bool addUser(std::pair<string, string> & kv);				// add a new username and password.
		bool addUser(std::pair<string, string> && kv);				// move version of addUser.
		bool removeUser(const string & k);							// delete an existing user with username k.
		bool changePassword(const pair<string, string> &p, const string & newpassword);		// change an existing user's password.
		bool find(const string & user);								// check if a user exists (if user is in the hash table).
		void dump();												// show the structure and contents of the HashTable object to the screen.
		size_t size();												// return the size of the HashTable (the number of username/password pairs in the table).
		bool write_to_file(const char *filename);					// save the username and password combination into a file.
		
	private:
		string encrypt(const string & str);			// encrypt the parameter str and return the encrypted string.
		HashTable<string, string> pServer;		// ???
};