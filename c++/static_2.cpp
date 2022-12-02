/*
Static use on global variable means it want to weaken its usable scope, making it availibe for only this file
Static use in function or class means its life cycle is as long as the program
it'll not be recycle after the function ends.
*/

int global_var = 123; // Available for all file, but other file need to declare extern to access
static int static_var = 456; // Only use by this file, can't access by other file