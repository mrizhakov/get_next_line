//  new_line_index return the index of buf which has \n
//  Does not work with BUFFER_SIZE = 1, have to fix it
//  better implementation would be to make new_line_index as an array of indexes of positions of \n and \0 in buf
//  
//  better code structure would be(protocode) :
/*
get_next_line(fd)
{
static int NEWLINES_PRINTED of how many new lines were printed out 
static int NEWLINES_READ of how many new lines were read from file
static array of positions of indexes of \n and \0 in storage
static * STORAGE to append all info read from BUF


function append_to_storage is run in case BUF_NEWLINE_INDEXES is empty
it's function are :
a. to read file to buf, append it to STORAGE, return STORAGE
b. count NEWLINES_READ and return it to get_next_line as a static int

function return_new_string runs in case NEWLINES_PRINTED is smalled than NEWLINES_READ
It will run NEWLINES_READ - NEWLINES_PRINTED times
it's function are :
a. check ifreturn new line from combination 

}

*/

//
//