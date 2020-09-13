#include "file.hpp"
#include "directory.hpp"

using namespace std;


void File::copy_file(File* destination)
{
	destination->change_info(information);
}

void File::move(Directory* destination)
{
	destination->insert_file(this);
	path = destination->get_path();
}

void File::change_info(vector<char> new_info)
{
	information.clear();
	for (int i = 0; i < new_info.size(); ++i)
	{
		information.push_back(new_info[i]);
	}	
}

int File::show_size()
{
	cout << information.size()/1000 << " Kb" << endl;
	return (information.size()/1000);
}
