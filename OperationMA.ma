[top]
components : scheduler@Scheduler 
components : doctor@DOCTOR 
components : nurse@Nurse 
components : Operationroom

out : out
in : in

Link : in in@scheduler
Link : out@scheduler in@doctor
Link : out@doctor in@nurse
Link : out@nurse in@Operationroom
Link : out@Operationroom out
Link : done@Operationroom done@scheduler

[scheduler]
preparation : 00:00:07:000 

[doctor]
distribution : normal
mean : 3
deviation : 1

[nurse]
distribution : normal
mean : 2
deviation : 1

[Operationroom]
components : equipment@Equipment
components : operation@Operation

in : in
out : out done
Link : in in@equipment
Link : out@equipment in@operation
Link : out@operation out
Link : done@operation done

[equipment]
distribution : normal
mean : 2
deviation : 1

[operation]
distribution : normal
mean : 2
deviation : 1

