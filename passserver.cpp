
/* Name: Andrew Stade
Date: 11/23/2020
Section: COP 4530 */

#include "passserver.h"
#include "hashtable.h"

PassServer::PassServer(size_t size)								// constructor, create a hash table of the specified size.
{
}

PassServer::~PassServer()												// destructor.
{
	pServer.clear();
}

bool PassServer::load(const char *filename)							// load a password file into the HashTable object.
{
	return(pServer.load(filename));
}

bool PassServer::addUser(std::pair<string, string> & kv)				// add a new username and password.
{
	return(pServer.insert(make_pair(kv.first,encrypt(kv.second))));
}

bool PassServer::addUser(std::pair<string, string> && kv)				// move version of addUser.
{
	return(pServer.insert(move(make_pair(kv.first,encrypt(kv.second)))));
}

bool PassServer::removeUser(const string & k)							// delete an existing user with username k.
{
	return(pServer.remove(k));
}

bool PassServer::changePassword(const pair<string, string> &p, const string & newpassword)		// change an existing user's password.
{
	if(pServer.match(make_pair(p.first, encrypt(p.second))) == true && encrypt(p.second) != encrypt(newpassword))
	{
		pServer.insert(make_pair(p.first, encrypt(newpassword)));
		return true;
	}
	return false;
}

bool PassServer::find(const string & user)								// check if a user exists (if user is in the hash table).
{
	return(pServer.contains(user));
}

void PassServer::dump()												// show the structure and contents of the HashTable object to the screen.
{
	pServer.dump();
}

size_t PassServer::size()											// return the size of the HashTable (the number of username/password pairs in the table).
{
	return(pServer.size());
}

bool PassServer::write_to_file(const char *filename)					// save the username and password combination into a file.
{
	return(pServer.write_to_file(filename));
}
	
string PassServer::encrypt(const string & str)			// encrypt the parameter str and return the encrypted string.
{
	char salt[] = "$1$########";
	char *password = new char [100];
	strcpy(password, str.c_str());
	string newPass = crypt(password, salt);
	return newPass.substr(12);
}