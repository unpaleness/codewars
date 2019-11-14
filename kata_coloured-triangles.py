def new_colour(colour1, colour2):
    if colour1 == colour2:
        return colour1
    if colour1 == 'R':
        if colour2 == 'G':
            return 'B'
        else:
            return 'G'
    elif colour1 == 'G':
        if colour2 == 'R':
            return 'B'
        else:
            return 'R'
    elif colour1 == 'B':
        if colour2 == 'R':
            return 'G'
        else:
            return 'R'

def triangle(row):
    if len(row) <= 1:
        return row
    new_row = ''
    for i in range(0, len(row) - 1):
        new_row += new_colour(row[i], row[i + 1])
    return triangle(new_row)

print(triangle('RGBRGB'))
