import subprocess

base_dir = r'C:\projects\game_programming_start_to_finish'

args = [
    ('git add:',['git','add',base_dir]),#add
    ('git commit:',['git','commit','-m','update']),#commit
    ('git commit:',['git','push']),#push
]

for prompt,arg in args:
    print(f"\n\n{prompt}\n\n")
    subprocess.run(arg)
    print(f'\n\nSuccess\n\n')

print("Repository updated")