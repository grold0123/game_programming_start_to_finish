import subprocess,sys,time,os,pathlib,shutil




if len(sys.argv) > 1:
    base_dir = r'C:\projects\game_programming_start_to_finish'
    project_name = sys.argv[1]
    source_dir_name = base_dir + '/' + project_name

    # create build objects
    args = [
        'g++',
        f'{base_dir}/source/{project_name}/*.cpp',
        '-o',
        f'{base_dir}/build/{project_name}.exe',
        '-L',
        'lib',
        '-I',
        'include',
        '-l',
        'SDL3_image',
        '-l',
        'SDL3',
    ]

    result = subprocess.run(args)

    if result.returncode != 0:
        print('\n\nBuild unsuccesful\n\n')
    else:
        print('\n\nBuild succesful\n\n')
        print(f'Opening file: {source_dir_name}.exe\n\n')
        time.sleep(.8)
        os.system("cls")
        # run exe file
        subprocess.run([f'{base_dir}/build/{project_name}.exe'])
        
    