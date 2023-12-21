import random

# Generate 200 random integers between 1 and 100
random_integers = [random.randint(-1000000000, 1000000000) for _ in range(500)]

# Write the integers to a file named "input.txt"
with open("random500.txt", "w") as f:
   f.write(" ".join(str(i) for i in random_integers))

print("OK")
