#!/bin/sh

DIR=""
INC="inc"
SRC="src"

NAME=""
CLASS=""
HEADR=""
VIM_COMMANDS=":Stdheader\ndd\n:wq"

# Colors, for beauty
R='\033[31m' # Red
Y='\033[33m' # Yellow
G='\033[32m' # Green
C='\033[36m' # Cyan
B='\033[34m' # Blue
P='\033[35m' # Purple
W='\033[37m' # White
N='\033[0m'	 # No Color

## Code ########################################
echo "\033[0m\c" #clear the font styling

echo "${G}Directory? ${W}\c"
read DIR

mkdir -p $DIR
mkdir -p $DIR$INC
mkdir -p $DIR$SRC

echo "${G}Class name? ${W}\c"
read NAME
CLASS="$DIR$SRC/$NAME.class.cpp"
HEADR="$DIR$INC/$NAME.class.hpp"

echo "${G}Import class contents?"
echo "Type the name of the class or leave empty to ignore. ${W}\c"
read OLDCLASS
if [ "$OLDCLASS" != "" ] ; then
	cat "$DIR$SRC/$OLDCLASS.class.cpp" >> $CLASS
	cat "$DIR$INC/$OLDCLASS.class.hpp" >> $HEADR

	STR=":Stdheader\n:%s/^#ifndef \w\+_/#ifndef"
	STR="$STR $(echo $NAME | awk '{print toupper($0)}')_/\n"
	STR="$STR:%s/^# define \w\+_/# define"
	STR="$STR $(echo $NAME | awk '{print toupper($0)}')_/\n"
	STR="$STR:%s/$OLDCLASS/$NAME/g\n:wq"

	echo "$STR" >> .vimheader$NAME
	echo ":Stdheader\n:%s/$OLDCLASS/$NAME/g\n:wq" >> .vimclass$NAME
	vim -s .vimclass$NAME $CLASS
	vim -s .vimheader$NAME $HEADR
	rm .vimheader$NAME
	rm .vimclass$NAME
	echo "${R}Done.${NOC}"
	exit 0
fi

STR=":Stdheader\ndd\n:wq"
echo "$STR" >> .vimcommand$NAME
vim -s .vimcommand$NAME $CLASS
vim -s .vimcommand$NAME $HEADR
rm .vimcommand$NAME

echo "#ifndef $(echo $NAME | awk '{print toupper($0)}')_CLASS_HPP" >> $HEADR
echo "# define $(echo $NAME | awk '{print toupper($0)}')_CLASS_HPP" >> $HEADR
echo "\n# include <iostream>\n# include <string>" >> $HEADR
echo "class $NAME {\n" >> $HEADR
echo "public:\n" >> $HEADR
echo "\t$NAME(void);" >> $HEADR
echo "\t$NAME(/* args */);" >> $HEADR
echo "\t$NAME($NAME const & old);" >> $HEADR
echo "\t$NAME(void);" >> $HEADR
echo "\t~$NAME(void); // to be updated" >> $HEADR
echo "\n\t$NAME\t\t\t&operator=($NAME const &old);" >> $HEADR
echo "\n\tvoid\t\t\tsampleFunction(void) const;" >> $HEADR
echo "\nprivate:\n" >> $HEADR
echo "\tint\t\t_privateFoo;" >> $HEADR
echo "\n};\n" >> $HEADR
echo "std::ostream\t&operator<<(std::ostream &o, $NAME const &c);" >> $HEADR
echo "\n#endif" >> $HEADR

echo "#include <iostream>\n#include <string>" >> $CLASS
echo "#include \"$NAME.class.hpp\"\n" >> $CLASS
echo "$NAME::$NAME(void) : _privateFoo(0) {" >> $CLASS
echo "\tstd::cout << \"$NAME Default Constructor\" << std::endl;" >> $CLASS
echo "\treturn;\n}\n" >> $CLASS
echo "$NAME::$NAME(/*args*/) : _privateFoo(/*args*/) {" >> $CLASS
echo "\tstd::cout << \"$NAME Parametric Constructor\" << std::endl;" >> $CLASS
echo "\treturn;\n}\n" >> $CLASS
echo "$NAME::$NAME($NAME const &old) {" >> $CLASS
echo "\tstd::cout << \"$NAME Copy Constructor\" << std::endl;" >> $CLASS
echo "\t*this = old;\n\treturn;\n}\n" >> $CLASS
echo "$NAME::~$NAME(void) {" >> $CLASS
echo "\tstd::cout << \"$NAME Destructor\" << std::endl;" >> $CLASS
echo "\treturn;\n}\n" >> $CLASS
echo "void\t\t\t$NAME::sampleFunction(void) const\n{" >> $CLASS
echo "\tstd::cout << \"$NAME Sample Function\" << std::endl\n}\n" >> $CLASS
echo "$NAME\t\t\t\t&$NAME::operator=($NAME const &old)\n{" >> $CLASS
echo "\tstd::cout << \"$NAME Assignment Operator\" << std::endl;" >> $CLASS
echo "\tif (this != &old)\n\t\tthis->_privateFoo = old.getFoo();" >> $CLASS
echo "\treturn *this;\n}\n" >> $CLASS
echo "std::ostream\t&operator<<(std::ostream &o, $NAME const &c)\n{" >> $CLASS
echo "\to << \"To String Function of $NAME: \" << c.getFoo();" >> $CLASS
echo "\treturn (o);\n}" >> $CLASS
