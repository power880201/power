%% Initial position computation

TH_set=1.5;
V_int=36;        % kph
d_offset=2;
L=4.5;           % car length

x=TH_set*(V_int/3.6)+d_offset+L


%% Record Path

% NEDC
load('H:\我的雲端硬碟\110448005\TJA\code\NEDC_path.mat')

% 200-m Radius Right, 100-m Radius Left
load('H:\我的雲端硬碟\110448005\TJA\code\200_100radius.mat')

% X_path=X_HV_m;
% Y_path=Y_HV_m;
% s_path=Station_HV_m;




%% ACC- TH & Speed Mode
close()

figure(1)

subplot(231)
plot(C_tick_time,HV_kph,'b','LineWidth',2)
hold on
plot(C_tick_time,PV_kph,'r','LineWidth',2)
hold on
grid;
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Velocity (kph)','fontsize',14,'FontWeight','bold')
legend('HV','PV','fontsize',8)
ylim([min([HV_kph;PV_kph])-10 max([HV_kph;PV_kph])+10])
hold off

subplot(232)
plot(C_tick_time,Desired_distance,'r',C_tick_time,RR,'b','LineWidth',2)
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Clearance (m)','fontsize',14,'FontWeight','bold')
legend('Desired','Actual','fontsize',8)
ylim([min([Desired_distance;RR])-10 max([Desired_distance;RR])+10])
grid;

hold off

subplot(233)
plot(C_tick_time,TH_ref,'r',C_tick_time,TH,'b','LineWidth',2)
grid;
hold on
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('TH (sec)','fontsize',14,'FontWeight','bold')
legend('TH_r_e_f','TH','fontsize',8)
ylim([min([TH_ref;TH])-1 max([TH_ref;TH])+1])

subplot(234)
plot(C_tick_time,Jerk_x,'b','LineWidth',2)
hold on
plot(C_tick_time,Jerk_x_Up_Limit,'r--','LineWidth',2)
hold on
plot(C_tick_time,Jerk_x_Low_Limit,'r--','LineWidth',2)
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Lon.Jerk (mps3)','fontsize',14,'FontWeight','bold')
ylim([min([Jerk_x;Jerk_x_Low_Limit])-2 max([Jerk_x;Jerk_x_Up_Limit])+2])
grid;


subplot(235)
plot(C_tick_time,Ax_HV_mps2,'b','LineWidth',2)
hold on
plot(C_tick_time,Ax_Up_Limit,'r--','LineWidth',2)
hold on
plot(C_tick_time,Ax_Low_Limit,'r--','LineWidth',2)
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Lon.Accel (mps2)','fontsize',14,'FontWeight','bold')
ylim([min([Ax_HV_mps2;Ax_Low_Limit])-2 max([Ax_HV_mps2;Ax_Up_Limit])+2])
grid;

subplot(236)
plot(C_tick_time,Acc_Mode,'b','LineWidth',2)
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Mode','fontsize',14,'FontWeight','bold')
ylim([-0.5 1.5])
text(min(C_tick_time)+15,1.35,'0 - TH MODE')
text(min(C_tick_time)+15,1.15,'1 - Speed MODE')
grid;

set(gcf,'unit', 'centimeters', 'position',[15 2.8 21.6 13.6]);


%% ACC- Speed Mode

close()

figure(2)

subplot(221)
plot(C_tick_time,HV_kph,'b','LineWidth',2)
hold on
% plot(C_tick_time,V_ref_kph,'r','LineWidth',2)  %'V_x,TAP'
% hold on
plot(C_tick_time,55*ones(length(C_tick_time)),'r','LineWidth',2)
grid;
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Velocity (kph)','fontsize',14,'FontWeight','bold')
legend('HV','V_s_e_t','fontsize',8)
ylim([20 70])
xlim([0 max(C_tick_time)])
hold off

subplot(222)
plot(C_tick_time,Jerk_x,'b','LineWidth',2)
hold on
plot(C_tick_time,-2.5*ones(length(C_tick_time)),'r--','LineWidth',2)
hold on
plot(C_tick_time,2.5*ones(length(C_tick_time)),'r--','LineWidth',2)
xlabel('Time(sec)','fontsize',14,'FontWeight','bold')
ylabel('Lon.Jerk (mps3)','fontsize',14,'FontWeight','bold')
ylim([-3 3])
xlim([0 max(C_tick_time)])
grid;


subplot(223)
plot(C_tick_time,Ax_HV_mps2,'b','LineWidth',2)
hold on
plot(C_tick_time,-2*ones(length(C_tick_time)),'r--','LineWidth',2)
hold on
plot(C_tick_time,2*ones(length(C_tick_time)),'r--','LineWidth',2)
xlabel('Time(sec)','fontsize',14,'FontWeight','bold')
ylabel('Lon.Acceleration(mps2)','fontsize',14,'FontWeight','bold')
ylim([-3 3])
xlim([0 max(C_tick_time)])
grid;

set(gcf,'unit', 'centimeters', 'position',[15 2.8 16.4 15.4]);

%% ACC+LFC

close()

figure(3)

subplot(221)
plot(X_path,Y_path,'b','LineWidth',2)
hold on
plot(X_HV_m,Y_HV_m,'r','LineWidth',2)
hold on
grid;
xlabel('X (m)','fontsize',14,'FontWeight','bold')
ylabel('Y (m)','fontsize',14,'FontWeight','bold')
legend('ref','HV','fontsize',8)
ylim([min([Y_path;Y_HV_m])-10 max([Y_path;Y_HV_m])+10])
hold off

subplot(222)
plot(C_tick_time,Jerk_y,'b','LineWidth',2)
hold on
plot(C_tick_time,Jerk_y_Up_Limit,'r--','LineWidth',2)
hold on
plot(C_tick_time,Jerk_y_Low_Limit,'r--','LineWidth',2)
grid;
xlabel('Time(sec)','fontsize',14,'FontWeight','bold')
ylabel('Lat.Jerk (mps3)','fontsize',14,'FontWeight','bold')
ylim([min([Jerk_y;Jerk_y_Low_Limit])-1 max([Jerk_y;Jerk_y_Up_Limit])+1])
hold off

subplot(223)
plot(C_tick_time,y_error,'b','LineWidth',2)
grid;
xlabel('Time(sec)','fontsize',14,'FontWeight','bold')
ylabel('y_e (m)','fontsize',14,'FontWeight','bold')
ylim([min(y_error)-0.2 max(y_error)+0.2])
hold off

subplot(224)
plot(C_tick_time,Jerk_y,'b','LineWidth',2)
hold on
plot(C_tick_time,Jerk_y_Up_Limit,'r--','LineWidth',2)
hold on
plot(C_tick_time,Jerk_y_Low_Limit,'r--','LineWidth',2)
grid;
xlabel('Time(sec)','fontsize',14,'FontWeight','bold')
ylabel('Lat.Jerk (mps3)','fontsize',14,'FontWeight','bold')
ylim([min([Jerk_y;Jerk_y_Low_Limit])-1 max([Jerk_y;Jerk_y_Up_Limit])+1])
hold off

set(gcf,'unit', 'centimeters', 'position',[15 2.8 16.4 15.4]);