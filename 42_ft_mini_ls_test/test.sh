mkdir TEST
# <no_option>
./ft_mini_ls > TEST/ft_no_option.txt
ls -1tr > TEST/real_no_option.txt
# <option -G>
# ./ft_mini_ls -G > TEST/ft_option_G.txt
# ls -1tr -G > TEST/real_option_G.txt

COUNT=0

# <no_option>
bash ./42_ft_mini_ls_test/diff_check.sh TEST/ft_no_option.txt TEST/real_no_option.txt "no_option"
if test $? -eq 1; then
    COUNT=$(( COUNT + 1 ))
fi
# <option -G>
# bash ./42_ft_mini_ls_test/diff_check.sh TEST/ft_option_G.txt TEST/real_option_G.txt "option -G"
# if test $? -eq 1; then
#     COUNT=$(( COUNT + 1 ))
# fi


if test $COUNT -eq 1; then
    echo -e "\n\033[0;32m$USER さん！\ndiffなく書けています！完璧！！！\033[0;39m\n"
else
    echo -e  "\n\033[0;31m上のパターンでエラーが出ています！！\033[0;m\n"
fi

rm -rf TEST