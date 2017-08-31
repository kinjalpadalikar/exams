// Write a function that when given a array of letters as input
// returns a new list, with those same characters as output, but any vowels
// should be replaced with the character '*'


// INPUT ['h', 'e', 'l', 'l', 'o']
// OUTPUT ['h', '*', 'l', 'l', '*']
// OUTPUT ['*, '*', '*', '*', '*']
var isVowel = function(character)
// isVowel is a function which accepts characters
{
  var vowels = ['a', 'e', 'i', 'o', 'u'];
  for (var i = 0; i < vowels.length; i++)
  {
    //we check each character to be a vowel, if it is, it returns true, if not it returns false
    if (character === vowels[i])
    {
      return true;
    }
  }
  return false;
}


var input = ['h', 'e', 'l', 'l', 'o'];

// we itterate over each input character to check if it is a vowel
for (var i = 0; i < input.length; i++){

  var character = input[i];

  // we call isVowel on variable character to check if it is a vowel
  if(isVowel(character))
  {
    //we replace all vowels with *
    input[i] = '*';
  }
}

console.log(input)



