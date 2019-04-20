/*
 * April 2019
 * Author: Pramod (Veer) Kumar
 * Problem statement: Please read "Merchants Guide to Galaxy.pdf" in same folder
 */

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

map<string,char> galatic_roman_map;
map<string, double> metal_to_cost_map;

int decimal_value(char c) 
{ 
    if (c == 'I') 
        return 1; 
    if (c == 'V') 
        return 5; 
    if (c == 'X') 
        return 10; 
    if (c == 'L') 
        return 50; 
    if (c == 'C') 
        return 100; 
    if (c == 'D') 
        return 500; 
    if (c == 'M') 
        return 1000; 
  
    return -1; 
}
int convert_roman_to_decimal (string &rom_str) {
    int value = 0;
    if (rom_str.size()==0) {return -1;}
    for (int i=0; i < rom_str.length(); i++) {
        int s1 = decimal_value(rom_str[i]);
        if(s1 == -1){
            /* Invalid roman character */
            return -1;
        }
        if (i+1 < rom_str.length()) { 
            int s2 = decimal_value(rom_str[i+1]); 
            if (s1 == -1) {
                /* Invalid roman character */
                return -1;
            }
            if (s1 >= s2) { 
                // Value of current symbol is greater 
                // or equal to the next symbol 
                value = value + s1; 
            } else { 
                value = value + s2 - s1; 
                i++; // Value of current symbol is 
                     // less than the next symbol 
            } 
        } else { 
            value = value + s1; 
            i++; 
        }     
    }
    return value;
}
template <class Container>
void split(const string& str, Container& cont)
{
    char delim = ' ';
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) {
        cont.push_back(token);
    }
}
void find_decimal_value_for_galatic_language (string& str) {
    vector<string> vec;
    split(str, vec);
    string roman_str, result;
    int temp, value;
    vector<int>::size_type sz = vec.size();
    if (sz < 5) {
        /* case: how much is ?
        */
        goto invalid_input;
    }
    for (int i = 3; i < sz-1; i++) {
        if (galatic_roman_map.find(vec[i]) != galatic_roman_map.end()) {
            temp = decimal_value(galatic_roman_map[vec[i]]);
            if(temp == -1){ 
                /*Invalid or unknown language, language grammer
                  is not there hence can't learn */
                goto invalid_input;
            } else {
                result.append(vec[i]);
                result.append(" ");
                roman_str.append(&galatic_roman_map[vec[i]]);
            }
        } else {
            goto invalid_input;
        }
    }
    value = convert_roman_to_decimal(roman_str);
    result.append(" is ");
    result.append(to_string(value));
    cout<<"\n"<<result;
    return;
    
invalid_input:
    cout<<"\nI have no idea what you are talking about";
    return;
}
void find_num_of_credit (string& str) {
   // cout<<"\n finding credit for metal";
    vector<string> vec;
    split(str, vec);
    string roman_str, result;
    int temp, metal_count;
    vector<int>::size_type sz = vec.size();
    if (sz < 7) {
        /* case : how many Credits is Silver ?
         * case: how many Credits is glob ?
         */
        goto invalid_input;
    }
    /* second last element should be metal hence <sz-2 */
    for(int i = 4; i< sz-2; i++ ){
        if (galatic_roman_map.find(vec[i]) != galatic_roman_map.end()) {
            temp = decimal_value(galatic_roman_map[vec[i]]);
            if(temp == -1){ 
                /*Invalid or unknown language, language grammer
                  is not there hence can't learn */
                goto invalid_input;
            } else {
                result.append(vec[i]);
                result.append(" ");
                roman_str.append(&galatic_roman_map[vec[i]]);
            }
        } else {
            goto invalid_input;
        }
    }
    metal_count = convert_roman_to_decimal(roman_str);
    result.append(vec[sz-2]);
    result.append(" is ");
    if (metal_to_cost_map.find(vec[sz-2])!=metal_to_cost_map.end()) {
            result.append(to_string(metal_to_cost_map[vec[sz-2]]*metal_count));
            result.append(" Credits");
            cout<<"\n"<<result;
            return;
        } 
  invalid_input:
    cout<<"\nI have no idea what you are talking about";
    return;
}
void learn_metal_value(string& str) {
    vector<string> vec;
    string roman_str;
    split(str, vec);
    int temp = 0 ;
    vector<string>::iterator it = vec.begin();
    while (it!=vec.end()) {
        if (galatic_roman_map.find(*it) != galatic_roman_map.end()) {
            temp = decimal_value(galatic_roman_map[*it]);
            if(temp == -1){ 
                /*Invalid or unknown language, language grammer is not there hence can't learn */
                return;
            } else {
                roman_str.append(&galatic_roman_map[*it]);
            }
        } else {break;}
        it++;
    }
    int metal_count = convert_roman_to_decimal(roman_str);
    if( metal_count < 0) {
        return;
    } 
    string metal_name = *it;
    it++;
    if(it ==vec.end()){return;}
    it++; // as it is pointing to "is"
    if(it ==vec.end()){return;}
    stringstream cost_str(*it); 
    double cost = 0; 
    cost_str >> cost;
    
    double metal_unit_cost = cost/metal_count;
    metal_to_cost_map[metal_name] = metal_unit_cost;
/*    for (map<string, double>::iterator mit=metal_to_cost_map.begin(); mit!=metal_to_cost_map.end(); ++mit)
    cout << '\n'<< mit->first << " => " << mit->second;*/
    
    return;
}
void learn_galatic_number_system (string& str) {
    vector<string> vec;
    split(str, vec);
    if (vec.size()>3) {
        return;
    }
    galatic_roman_map[vec[0]] = vec[2][0];
   /*for (map<string, char>::iterator it=galatic_roman_map.begin(); it!=galatic_roman_map.end(); ++it)
    cout << it->first << " => " << it->second << '\n'; */
    return;
}
int main() {
    
    string input_str;
    string token_str[40];
    cout << "Please enter INPUT string(1 per line)\n";
    vector<string> words;
    while (1) {
        getline (cin, input_str);
        if (input_str.length() == 0) {
            
            break;
        }
        if(input_str.find("?")!= string::npos){
            //Question case
            if (input_str.find("how many Credit")!= string::npos) {
                // find credit
                find_num_of_credit(input_str);    
            } else {
                // calculate decimal value
                find_decimal_value_for_galatic_language(input_str);
            }
            
        } else {
            if(input_str.find("Credits")!=string::npos){
                learn_metal_value(input_str);                
            } else {
                learn_galatic_number_system(input_str);
            }
        }  
    }
    
}
