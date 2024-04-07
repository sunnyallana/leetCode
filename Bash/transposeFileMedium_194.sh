# Read from the file file.txt and print its transposed content to stdout.
awk '
{
    for (i = 1; i <= NF; i++) {
        if (NR == 1) {
            rows[i] = $i;
        } else {
            rows[i] = rows[i] " " $i;
        }
    }
}
END {
    for (i = 1; i <= NF; i++) {
        print rows[i];
    }
}
' file.txt
