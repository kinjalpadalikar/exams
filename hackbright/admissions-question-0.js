
var find = function(string, character, position)
{
    //search from the current character to the end
    var start = position;
    for (var i = start; i + 1 < string.length; i++)
    {
        // var back_i enables to start iteratting the string from the end
        var back_i = string.length - i - 1 + start;
        var newCharacter = string.charAt(back_i);

        //this condition will check if the new character is the one we are looking for
        if (newCharacter === character)
        {
           return back_i;
        }
    }

    return "did not find anything";
}
       // getCharacterPositions will get the index of the current and duplicate character
var getCharacterPositions = function(string)
{
    var maxSoFar = 0;
    var indicesSoFar = [undefined, undefined];

    for (var i = 0; i < string.length; i++)
    {
        // for the current character, find the position of the last matching character
        var lastPosition = find(string, string.charAt(i), i);

        // if we did find something, then we found a possible solution, process this character
        if ("did not find anything" !== lastPosition)
        {
            // get the difference/distance between the indices
            var difference = lastPosition - i;

            // figure out if this difference is the maximum so far, if so save it, and also save the positions
            if (difference > maxSoFar)
            {
                maxSoFar = difference;
                indicesSoFar = [i, lastPosition];
            }

        }
    }

    return indicesSoFar;
}

var test = function(string)
{
    var indices = getCharacterPositions(string);

    console.log("Positions for '" + string + "' are: " + indices.toString());
}

test("expire")
test("sleep")
test("characters")
test("yabcdey")
test("yabcyzdefgz")
test("abc")

