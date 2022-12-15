#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

string MinWindowSubstring(string strArr[], int arrLength) {

    int MaxArrLength = 50, MinArrLength = 1;
    
    string N = strArr[0]; 
    string K = strArr[1];

    int SizeOfCharN = N.size();
    int SizeOfCharK = K.size();

    int length = N.size();
    int counter = K.size();
    //the left(start) size and right(left) size of the string N
    int left = 0, right = 0, ansLeft = 0, ansRight = 0;
    bool flag = false;

    string answer = "";

    if (!(SizeOfCharN > MaxArrLength && SizeOfCharK > MaxArrLength) || !(SizeOfCharN < MinArrLength && SizeOfCharK < MinArrLength) || !(SizeOfCharN < SizeOfCharK)) {
        // create the map with char and int 
        map <char, int> map;

        //using for loop to check the size of the string K and input the Charaters that are in K string into the map 
        for (int i = 0; i < SizeOfCharK; i++) map[K[i]]++;

        //debuging to check is the K charters input to the map correctly
        /*for (auto it = map.cbegin(); it != map.cend(); ++it)
        {
            cout << it->first << ":" << it->second << endl;
        }*/

        //while loop to check is the right value is smaller then the size of the char N
        while (right < SizeOfCharN)
        {
            //create a char varialbe call c this equals to N array of the size of the right value
            char c = N[right];

            //cout << N[right]  << " : " << map[c] << " : "<< counter << endl;

            // if character in c matches the chatacters inside the map and it is not the end of the map
            if (map.find(c) != map.end()) {
                //cout << N[right]  << " : " << map[c] << ":"<< counter << endl;
                
                //if map c value is bigger then 0, counter value -1;
                if (map[c] > 0)counter--;
                //cout << N[right]  << " : " << map[c] << ":"<< counter << endl;

                map[c]--;

                //cout << N[right] << " : " << map[c] << ":" << counter << endl;
            }

            //while counter equals to 0 and left is smaller or equal to right
            while (counter == 0 && left <= right) {
                cout << left << ":" << right << ":" << length << endl;
                //if right takeaway left plus one is smaller or equal to length
                if (right - left + 1 <= length) {
                    //length is eqaul to right - left plus one
                    length = right - left + 1;
                    //cout << right << "-" << left << "+" << 1 << "=" << length << endl;
                    // flag is true;
                    flag = true;
                    // ansleft equals the current left and ansRight is equals to current right
                    ansLeft = left;
                    ansRight = right;

                }

                // if left and right is true then break the loop 
                if (left == right)break;

                // char c equals to N with left value as size
                c = N[left];

                // if character in c matches the chatacters inside the map and it is not the end of the map
                if (map.find(c) != map.end()) {
                    //map c value add one
                    map[c]++;

                    //if map c value is bigger then 0, counter value +1;
                    if (map[c] > 0)counter++;
                }

                //left add one
                left++;
            }

            //right add one
            right++;
        }

        //if flagg is not ture
        if (!flag) {
            return answer;
        }
        else
        {
            for (int i = ansLeft; i <= ansRight; i++) answer += N[i];
            return answer;
        }
	}
    else
    {
        cout << "There is some issues with your array" << endl;
        return "";
    }   
}

int main()
{
    string A[] = {"abhdaxcvbagtxatycb","abc"};
    /*string N = "ahffaksfajeeubsne";
    string K = "jefaa";*/
    int arrLength = sizeof(A) / sizeof(*A);
    
    cout << MinWindowSubstring(A, arrLength);
    return 0;
}


