import subprocess,pathlib,sys,os


if len(sys.argv) > 1:
    project_name = sys.argv[1]
    base_dir = pathlib.Path(r'C:\projects\game_programming_start_to_finish\source')

    # create project dir
    project_dir = base_dir/project_name
    project_dir.mkdir(exist_ok=True)

    # create main.cpp
    main = project_dir/'main.cpp'
    main.touch(exist_ok=True)

    with open(main,'w') as file:
        file.write('//===============================================\n')
        file.write(f'//{(project_name).upper()}\n')
        file.write('//===============================================\n')
        file.write('\n\n#include<iostream>')
        file.write('\n\nint main(){\n\n}')
    
    subprocess.run(['code',str(main)])

