jump 0 0 25  # go to load input
zero 6       # 4 is less_than 5 ?
zero 7
proj 4 6
proj 5 7
jump 4 5 15  # 4 is less than 5!
jump 6 7 18  # 4 is greater than 5!
incr 4
incr 7
jump 0 0 5
proj 1 10    # main: save input
proj 2 11
proj 1 4     # -> prepare call to less_than
proj 2 5
jump 0 0 1   # call less_than
proj 10 1    # if 4 < 5
proj 11 2
jump 0 0 20  # call sum r(0) <- r(1) + r(2)
proj 10 2    # if 5 < 4
proj 11 1
proj 1 0     # sum r(0) <- r(1) + r(2)
jump 3 2 255
incr 0
incr 3
jump 0 0 21
zero 3       # load input
zero 2
zero 1
zero 0
incr 1
incr 1
incr 2
incr 2
incr 2
jump 0 0 10  # go to main
