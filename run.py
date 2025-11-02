import subprocess,sys,time,os




if len(sys.argv) > 1:
    base_dir = r'C:\projects\game_programming_start_to_finish'
    project_name = sys.argv[1]
    source_dir_name = base_dir + '/' + project_name

    #builld args
    args = [
        'g++',
        f'{base_dir}/source/{project_name}/*.cpp',
        '-o',
        f'{source_dir_name}/build/{source_dir_name}.exe'
    ]

    result = subprocess.run(args)
    if result.returncode != 0:
        print('\n\nBuild unsuccesful\n\n')
    else:
        print('\n\nBuild succesful\n\n')
        print(f'Opening file: {source_dir_name}.exe\n\n')
        time.sleep(.8)
        os.system("cls")
        
    