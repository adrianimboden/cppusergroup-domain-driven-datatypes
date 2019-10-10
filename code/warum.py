#!/usr/bin/env python3

secret_global = None


def do_something(value):
    global secret_global
    value.append('new fancy value')  # no const
    secret_global = value  # everything is shared


my_list = [1, 2, 3]
do_something(my_list)
assert (my_list == [1, 2, 3])
