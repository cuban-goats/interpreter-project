# 
# Toaster
#
# Created on: Oct 14, 2024
#   Author: Erik Koston

# Toaster is a stack based programming language

#### basic operations

# push value onto a stack
TOASTERPUSH

# remove value from the stack (which the pointer points to)
TOASTERPOP

# pop 2 numbers from the stack and push the sum
TOASTERADD

# pop 2 numbers from the stack and push subtracton of the first one from the second
TOASTERSUB

# print the string literal to the terminal
TOASTERPRINT

# read numbers from IO output and push it to the stack
TOASTERREAD

# stop program
TOASTERSTOP

#### labels (necessary for creating loops)

# jump to label if top stack is 0
TOASTERJUMP.EQ.0

# jump to label if top of stack greater then 0
TOASTERJUMP.GT.0

# lavels can't start with 'TOASTER'
# example label :
LOOP:

# print output
TOASTERPRINT
