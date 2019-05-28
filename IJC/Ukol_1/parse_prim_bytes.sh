#! /bin/bash

ascii2bit() {
    echo -n "$1" | xxd -b | awk '{print $2}'
}

bit2ascii() {
    echo $1 | perl -lape '$_=pack"(B8)*",@F'
}


BYTES_PRINT=10000

#init array of prime numbers
primes=( $(factor {18..10000} | awk 'NF==2{print $2}') )

#echo ${primes[@]}

#for start_byte in {-20..20} # kdyz jsem hledal pocatecni byte pozici.
for start_byte in -15
do
echo "Start byte: $start_byte !!!"

#print bytes in bit format to tmp file, one byte, one line
xxd -b -c 1 du1-obrazek.ppm | awk '{print $2}' | nl -v $start_byte | head -$BYTES_PRINT > tmp_bytes.tmp

#cat tmp_bytes.tmp

spacer=0
msg_char=()
full_msg=()

# for each line, get num line and if line is prime, print bits in this byte
while read byte; do
    # if actual number of line is in prime array (18 to 10000) (we start with prime 19)
    numline=$(echo "$byte" | awk '{print $1}')
    if [[ " ${primes[@]} " =~ " ${numline} " ]]; then
        # echo only LSB bits
        if [ "$1" == "-v" ]; then
            # echo whole line as it is
            echo "$byte"
            
            # echo only LSB bits
            echo "$byte" | tail -c 2
        fi
        # append this bite to the end of array
        msg_char+=$(echo "$byte" | tail -c 2)
        
        (( spacer++ ))

        #verbose output
        if [ "$1" == "-v" ]; then
            if [ "$spacer" == "4" ]; then
                echo ""
            fi
        fi
        if [ "$spacer" == "8" ]; then
            if [ "$1" == "-v" ]; then
                echo ""
                echo ""
                #echo "------------------------"
                echo $msg #vypise bity znaku
            fi

            # prevede obracene pole bitu na ascii znak.
            ascii_char=$(bit2ascii $(echo "$msg_char" | rev))
            full_msg+=$ascii_char

            if [ "$ascii_char" == '' ]; then
                echo $full_msg
                full_msg=()
                #exit 0
            fi  

            msg_char=()
            spacer=0
        fi
    fi
done <tmp_bytes.tmp

#delete temp file
rm tmp_bytes.tmp

echo $full_msg
done

exit 1

#for i in {1..10}; do echo "nl"; done | nl | awk '{print $1}'




