# include <sstream>
# include <string>
# include <iostream>

using namespace std;
#include <fstream>
#include <string>
#include <vector>

std::vector <string> lines_of_file;
std::vector<string>::const_iterator A; 
std::vector<string>::const_iterator Z; 
std::vector <string> line_chars;
std::vector <vector<char>> document;

struct char_count{
	char specific_char;
	int times_seen;
	};

std::vector <char_count> alminac;

int main() 
{ 
    std::ifstream file("Time_Machine_des_cbc.txt");
    std::string str; 
    while (std::getline(file, str))
    {

	    lines_of_file.push_back(str);
    }
    A = lines_of_file.begin();
    Z = lines_of_file.end();
    std::vector<string>::const_iterator i;

    for (i = A; i != Z;  i++){
	    string this_i;
	    this_i = *i;
	    int this_i_len = this_i.length();
	    char this_char;
	    vector<char> this_line;
	    for (int j = 0; j < this_i_len; j++){
	    	this_char = this_i.at(j);
		bool viable_candidate = true;
		for (std::vector<char_count>::const_iterator k = alminac.begin(); k != alminac.end(); k++){
			char_count alminac_member;
			alminac_member = *k;
			if(alminac_member.specific_char == this_char){	


				alminac_member.times_seen = alminac_member.times_seen + 1; 
				viable_candidate = false;
				alminac.erase(k);
				alminac.insert(alminac.begin(), alminac_member);
				}	
			}
		if(viable_candidate == true){
			char_count new_char;
			new_char.times_seen = 0;
			new_char.specific_char = this_char;
			alminac.push_back(new_char);	
			}
	    	this_line.push_back(this_char);
	    	}
	    document.push_back(this_line);
    	    }
    ofstream myfile;
    myfile.open ("TM_des_cbc_0.txt");

	
    for (std::vector<char_count>::const_iterator k = alminac.begin(); k != alminac.end(); k++){
    	char_count alminac_member;
       	alminac_member = *k;
	myfile<< int(alminac_member.times_seen)<<endl; 
	myfile<< alminac_member.specific_char<<endl; 
    
    	}
    myfile.close();


}
