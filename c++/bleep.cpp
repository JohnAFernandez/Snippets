#include <iostream>
#include <string>


using namespace std;

// This bleep function searches through a reference to the text string and for matches to the word string.
// A const reference is used for the word string to prevent accidental changes.  The text string is not const
// because you requested that the words in the text string be replaced, and so it needs to retain those 
// changes.  Alternatively, a new string can be created and returned by this function.
void bleep(const std::string& word, std::string& text) {

  // If the word is empty or longer than the text to check, there is nothing to change, so return early.
  if (word.empty() || word.size() > text.size())
    return;
   
  // This loop sets the i variable to where we are in the search.  
  // We can subtract word size since there cannot be a match shorter than the word.
  for (int i = 0; i < text.size() - word.size(); ++i) {
  
    // We will use this variable to ensure that we have a match
    bool match = true;

    // This nested loop goes through each character starting at the ith character.
    for (int j = 0; j < word.size(); ++j) {

      // This checks if we don't have a match between the string and substring.
      if (text[i+j] != word[j] ) {

        // Since one of the characters did not match, mark match as false and break to return to the outer loop.
        match = false;
        break;
      }
    
      // Replace the matched word if we found a match
      if (match){
        
        // Loop through the matching character
        for (int j = 0; j < word.size(); ++j){

          // Replace the matched character
          text[i+j] = '*';
        }        
      }
    }      
  }    
}


int main()
{
    std::string taco("I am a taco.");
    std::string word("taco");
    cout << taco << "\n";

    bleep(word, taco);

    cout << taco;
    
    return 0;
}
