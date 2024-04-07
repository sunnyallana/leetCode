# Read from the file file.txt and output all valid phone numbers to stdout.
grep -E '^\([0-9]{3}\) [0-9]{3}-[0-9]{4}$|^([0-9]{3}-){2}[0-9]{4}$' file.txt