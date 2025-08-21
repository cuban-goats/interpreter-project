# 
# ToasterLang
#
# Created on: Oct 14, 2024
#   Author: cuban-goats

# Toaster is a stack based programming language

#### basic operations

# push value onto a stack
TOASTERPUSH

# remove value from the stack
TOASTERPOP

# pop 2 numbers from the stack and push the sum
TOASTERADD

# pop 2 numbers from the stack and push subtraction
TOASTERSUB

# print the string literal to the terminal (which follows the print operation)
# string can't contain spaces yet
TOASTERPRINT "StringValue"

# read numbers from IO output and push it to the stack
TOASTERREAD

# stop program
TOASTERSTOP

#### labels
# necessary for creating loops

# jump to label if top stack is 0
# label declaration follows the instruction:
TOASTERJUMP.EQ.0 Label

# jump to label if top of stack greater then 0
TOASTERJUMP.GT.0 Label

# label is placed, where to jump to
# example label :
LOOP:
