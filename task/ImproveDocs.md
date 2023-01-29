# Description
Alot of documentation is not available - please document the code, tests, and CMake scripts so we can understand the project better in the future.

# Docs for units in library
to_alphabet_char:
    Returns character in base 64 alphabet that corrosponds to 6-bit input character.

to_original_char:
    Returns a character equal to the index value for an input alphabet character.

is_valid_b64:
    Returns true if each decoder word in input vector is a valid base 64 word.

Letter (class):
    Carries a dynamic sequence of bits from zero to eight bits - this is used for modifying
    bits of an unsigned char, and provides conversions to and from vector of bool and unsigned char.

write_stream: 
    Takes a specified amount of input from a reader function before running a specified
    writer function on the output - used to read streams words at a time, causing input-output
    or local side effects.

iterable_reader: 
    Generic reader for 'write_stream' that when used, iterates over an iterable object from
    begin to end, yielding a single letter from the stream each time it is executed until no
    output remains.

to_b64:
    Applies base 64 encoder function to output of selected reader function, writing
    each encoded word to a specified location using selected writer function.

decode_b64:
    Applies base 64 decoder function to output of selected reader function,
    writing decoded text to a specified location using selected writer function.

# Docs for valid base 64 word critera
- Must be 0 or 4 characters long.
- Must contain only letters from the base 64 alphabet, or padd character.
- Characters other than padd character must not exist in positions after first padd is found.
- Size of word without padds must be greater than or equal to 2.
- Number of padds must be equal to difference between 4 (decoder max word size), and size of word without existing padds