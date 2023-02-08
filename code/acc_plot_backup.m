%% Initial position computation

TH_set=1.5;
V_int=50;        % kph
d_offset=2;
L=4.5;           % car length

x=TH_set*(V_int/3.6)+d_offset+L

% 72kph 36.5
% 40kph 23.16
% 36kph 21.5
% 28kph 18.1667
% 15kph 12.75

%% Record LV

% ACC straight 40-60-40 kph 40sec
load('H:\我的雲端硬碟\110448005\TJA\code\LV_straight_40_60_40_kph_40_sec.mat')

% ACC straight_ISO22179_36kph_stop_test_40sec
load('H:\我的雲端硬碟\110448005\TJA\code\LV_straight_ISO22179_36kph_stop_test_40_sec.mat')

% ACC straight_ISO22178_50kph_stop_test_40sec
load('H:\我的雲端硬碟\110448005\TJA\code\LV_straight_ISO22178_50kph_stop_test_40_sec.mat')

% ACC straightNEDC_stop_and_go_test_206_sec
load('H:\我的雲端硬碟\110448005\TJA\code\LV_straight_NEDC_stop_and_go_test_206_sec.mat')

% ACC Straight East_into_curve_ISO21717_28kph_40sec
load('H:\我的雲端硬碟\110448005\TJA\code\LV_Straight_East_into_curve_ISO21717_28kph_40sec.mat')

% ACC Straight East_into_curve_ISO21717_72kph_24sec
load('H:\我的雲端硬碟\110448005\TJA\code\LV_Straight_East_into_curve_ISO21717_72kph_24sec.mat')

% ACC Straight East_into_cure_NEDC_206sec
load('H:\我的雲端硬碟\110448005\TJA\code\LV_Straight_East_into_curve_NEDC_206sec.mat')

% ACC Straight East_into_curve_40_60_40kph_40sec
load('H:\我的雲端硬碟\110448005\TJA\code\LV_Straight_East_into_curve_40_60_40kph_40sec.mat')

% ACC + LFC
load('H:\我的雲端硬碟\110448005\TJA\code\LV_200m_100m_radius_NEDC_206sec.mat')

load('H:\我的雲端硬碟\110448005\TJA\code\LV_Clothoid_S_Turn_NEDC_stop_and_go_test_206_sec.mat')


%%  Record APV

% ACC straight APV_40-60-40 kph 40sec
load('H:\我的雲端硬碟\110448005\TJA\code\APV_straight_40_60_40_kph_40_sec.mat')

% % ACC Straight APV_East_into_curve_ISO21717_28kph_40sec
load('H:\我的雲端硬碟\110448005\TJA\code\APV_Straight_East_into_curve_ISO21717_28kph_40sec.mat')


%% Record Path

% NEDC
load('H:\我的雲端硬碟\110448005\TJA\code\NEDC_path.mat')

% 200-m Radius Right, 100-m Radius Left
load('H:\我的雲端硬碟\110448005\TJA\code\200_100radius.mat')

% Straight East_into_curve
load('H:\我的雲端硬碟\110448005\TJA\code\Straight_East_into_curve.mat')

% S_Turn_path
load('H:\我的雲端硬碟\110448005\TJA\code\LV_Clothoid_S_Turn_path.mat')


Np=10;
X_path=X_HV_m;
Y_path=Y_HV_m;
s_path=Station_HV_m;

close()
plot(X_path,Y_path)


%% ACC- TH & Speed Mode

% close()

sim("acc")

figure(26)

subplot(231)
plot(C_tick_time,PV_kph,'r','LineWidth',2)
hold on
plot(C_tick_time,HV_kph,'b','LineWidth',2)
hold on
grid;
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Velocity (kph)','fontsize',14,'FontWeight','bold')
legend('PV','HV','fontsize',8)
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

subplot(235)
plot(C_tick_time,Jerk_x,'b','LineWidth',2)
hold on
plot(C_tick_time,Jerk_x_Up_Limit,'r--','LineWidth',2)
hold on
plot(C_tick_time,Jerk_x_Low_Limit,'r--','LineWidth',2)
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Lon.Jerk (mps3)','fontsize',14,'FontWeight','bold')
ylim([min([Jerk_x;Jerk_x_Low_Limit])-2 max([Jerk_x;Jerk_x_Up_Limit])+2])
ylim([-5.5 5.5])
grid;


subplot(234)
plot(C_tick_time,Ax_HV_mps2,'b','LineWidth',2)
hold on
plot(C_tick_time,Ax_Up_Limit,'r--','LineWidth',2)
hold on
plot(C_tick_time,Ax_Low_Limit,'r--','LineWidth',2)
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Lon.Accel (mps2)','fontsize',14,'FontWeight','bold')
% ylim([min([Ax_HV_mps2;Ax_Low_Limit])-2 max([Ax_HV_mps2;Ax_Up_Limit])+2])
ylim([-5.5 5.5])
legend('','ISO limit','fontsize',8)
grid;

subplot(236)
plot(C_tick_time,Acc_Mode,'b','LineWidth',2)
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Mode','fontsize',14,'FontWeight','bold')
ylim([-0.5 1.5])
text(min(C_tick_time)+15,1.35,'0 - Speed MODE')
text(min(C_tick_time)+15,1.15,'1 - TH MODE')
grid;

% subplot(236)
% plot(C_tick_time,(TH-TH_ref),'b','LineWidth',2)
% xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
% ylabel('TH_e_r_r_o_r','fontsize',14,'FontWeight','bold')
% ylim([min(TH-TH_ref)-0.2 max(TH-TH_ref)+0.2])
% grid;

set(gcf,'unit', 'centimeters', 'position',[15 2.8 23.6 13.6]);




%% LFC

% close()

% sim("acc")


figure(12)

subplot(231)
plot(X_ref,Y_ref,'b','LineWidth',2)
hold on
plot(X_HV_m,Y_HV_m,'r','LineWidth',2)
hold on
grid;
xlabel('X (m)','fontsize',14,'FontWeight','bold')
ylabel('Y (m)','fontsize',14,'FontWeight','bold')
legend('ref','HV','fontsize',8)
xlim([0 max([X_ref;X_HV_m])])
ylim([min([Y_ref;Y_HV_m])-10 max([Y_ref;Y_HV_m])+10])
hold off

subplot(232)
plot(C_tick_time,HV_kph,'b','LineWidth',2)
hold on
% plot(C_tick_time,PV_kph,'r','LineWidth',2)
% hold on
grid;
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Velocity (kph)','fontsize',14,'FontWeight','bold')
% legend('HV','PV','fontsize',8)
xlim([0 max(C_tick_time)])
ylim([min([HV_kph])-10 max([HV_kph])+10])
hold off

subplot(233)
plot(C_tick_time,Steer_SW_deg,'b','LineWidth',2)
grid;
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Steering angel (deg)','fontsize',14,'FontWeight','bold')
xlim([0 max(C_tick_time)])
ylim([min([Steer_SW_deg])-10 max([Steer_SW_deg])+10])
hold off

subplot(236)
plot(C_tick_time,y_error,'b','LineWidth',2)
grid;
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('y_e (m)','fontsize',14,'FontWeight','bold')
xlim([0 max(C_tick_time)])
ylim([-max(abs(y_error))-0.1 max(abs(y_error))+0.1])
hold off

subplot(234)
plot(C_tick_time,Ay_HV_mps2,'b','LineWidth',2)
hold on
plot(C_tick_time,Ay_Up_Limit,'r--','LineWidth',2)
hold on
plot(C_tick_time,Ay_Low_Limit,'r--','LineWidth',2)
grid;
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Lat. Accel. (mps2)','fontsize',14,'FontWeight','bold')
xlim([0 max(C_tick_time)])
ylim([min([Ay_HV_mps2;Ay_Low_Limit])-1 max([Ay_HV_mps2;Ay_Up_Limit])+1])
legend('','ISO limit')
hold off


subplot(235)
plot(C_tick_time,Jerk_y,'b','LineWidth',2)
hold on
plot(C_tick_time,Jerk_y_Up_Limit,'r--','LineWidth',2)
hold on
plot(C_tick_time,Jerk_y_Low_Limit,'r--','LineWidth',2)
grid;
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Lat.Jerk (mps3)','fontsize',14,'FontWeight','bold')
xlim([0 max(C_tick_time)])
ylim([min([Jerk_y;Jerk_y_Low_Limit])-1 max([Jerk_y;Jerk_y_Up_Limit])+1])
legend('','ISO limit')

set(gcf,'unit', 'centimeters', 'position',[15 2.8 23.6 13.6]);

%% 比較 Car-following
Leftdis_PV_switch=1;
sim("acc")
orginal.X_HV_m=X_HV_m;
orginal.Y_HV_m=Y_HV_m;
orginal.HV_kph=HV_kph;
orginal.Ay_HV_mps2=Ay_HV_mps2;
orginal.Jerk_y=Jerk_y;
orginal.y_error=y_error;
orginal.Steer_SW_deg=Steer_SW_deg;

save car_following.mat orginal

Leftdis_PV_switch=2;
sim("acc")
%% 比較 Cut-in

orginal.HV_kph=HV_kph;
orginal.TH=TH;
orginal.Ax_HV_mps2=Ax_HV_mps2;
orginal.Jerk_x=Jerk_x;
orginal.RR=RR;
orginal.TTC=TTC;

save TTC_strategy.mat orginal

%% Car-following 比較圖  run 追單點 再run 追前車軌跡(多點)

figure(32)

subplot(231)
plot(X_ref,Y_ref,'b','LineWidth',2)
hold on
plot(orginal.X_HV_m,orginal.Y_HV_m,'g','LineWidth',2)
hold on
plot(X_HV_m,Y_HV_m,'r','LineWidth',2)
hold on
grid;
xlabel('X (m)','fontsize',14,'FontWeight','bold')
ylabel('Y (m)','fontsize',14,'FontWeight','bold')
legend('ref','original','proposed','fontsize',8)
xlim([0 max([X_ref;X_HV_m])])
ylim([min([Y_ref;Y_HV_m])-10 max([Y_ref;Y_HV_m])+10])
hold off

subplot(232)
plot(C_tick_time,HV_kph,'b','LineWidth',2)
hold on
grid;
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Velocity (kph)','fontsize',14,'FontWeight','bold')
xlim([0 max(C_tick_time)])
ylim([min([HV_kph])-10 max([HV_kph])+10])
hold off

subplot(233)
plot(C_tick_time,orginal.Steer_SW_deg,'g','LineWidth',2)
hold on
plot(C_tick_time,Steer_SW_deg,'b','LineWidth',2)
grid;
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Steering angel (deg)','fontsize',14,'FontWeight','bold')
xlim([0 max(C_tick_time)])
ylim([min([Steer_SW_deg])-10 max([Steer_SW_deg])+10])
legend('original','proposed','fontsize',8)
hold off

subplot(236)
plot(C_tick_time,orginal.y_error,'g','LineWidth',2)
hold on
plot(C_tick_time,y_error,'b','LineWidth',2)
grid;
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('y_e (m)','fontsize',14,'FontWeight','bold')
xlim([0 max(C_tick_time)])
ylim([min([y_error;orginal.y_error])-0.1 max(abs(y_error))+0.1])
legend('original','proposed','fontsize',8)
hold off

subplot(234)
plot(C_tick_time,orginal.Ay_HV_mps2,'g','LineWidth',2)
hold on
plot(C_tick_time,Ay_HV_mps2,'b','LineWidth',2)
hold on
plot(C_tick_time,Ay_Up_Limit,'r--','LineWidth',2)
hold on
plot(C_tick_time,Ay_Low_Limit,'r--','LineWidth',2)
grid;
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Lat. Accel. (mps2)','fontsize',14,'FontWeight','bold')
xlim([0 max(C_tick_time)])
ylim([min([Ay_HV_mps2;Ay_Low_Limit])-1 max([Ay_HV_mps2;Ay_Up_Limit])+1])
legend('original','proposed','ISO limit','fontsize',8)
hold off


subplot(235)
plot(C_tick_time,orginal.Jerk_y,'g','LineWidth',2)
hold on
plot(C_tick_time,Jerk_y,'b','LineWidth',2)
hold on
plot(C_tick_time,Jerk_y_Up_Limit,'r--','LineWidth',2)
hold on
plot(C_tick_time,Jerk_y_Low_Limit,'r--','LineWidth',2)
grid;
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Lat.Jerk (mps3)','fontsize',14,'FontWeight','bold')
xlim([0 max(C_tick_time)])
ylim([min([Jerk_y;Jerk_y_Low_Limit])-1 max([Jerk_y;Jerk_y_Up_Limit])+1])
legend('original','proposed','ISO limit','fontsize',8)

set(gcf,'unit', 'centimeters', 'position',[15 2.8 23.6 13.6]);

figure(2)
plot(C_tick_time,Vy_HV_kph,'b','LineWidth',2)
hold on
plot(C_tick_time,Vy_e_output,'r','LineWidth',2)
grid;
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Lat.Velocity (kph)','fontsize',14,'FontWeight','bold')
legend('carsim','estimated','fontsize',8)
xlim([0 max(C_tick_time)])
ylim([min([Vy_HV_kph;Vy_e_output])-0.1 max([Vy_HV_kph;Vy_e_output])+0.1])

%% Cut-in 比較圖    run原版 再run ttc

% close()
figure(25)

subplot(231)
plot(C_tick_time,PV_kph,'r','LineWidth',2)
hold on
plot(C_tick_time,orginal.HV_kph,'g','LineWidth',2)
hold on
plot(C_tick_time,HV_kph,'b','LineWidth',2)
hold on
grid;
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Velocity (kph)','fontsize',14,'FontWeight','bold')
legend('PV','original','HV','fontsize',8)
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
plot(C_tick_time,TH_ref,'r','LineWidth',2)
hold on
plot(C_tick_time,orginal.TH,'g','LineWidth',2)
hold on
plot(C_tick_time,TH,'b','LineWidth',2)
hold on
plot(C_tick_time,TH_new,'black','LineWidth',2)
grid;
hold on
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('TH (sec)','fontsize',14,'FontWeight','bold')
legend('TH_r_e_f','original','TH','fontsize',8)
legend('TH_r_e_f','original','proposed','filter','fontsize',8)
ylim([min([TH_ref;TH])-1 max([TH_ref;TH])+1])

subplot(235)
plot(C_tick_time,orginal.Jerk_x,'g','LineWidth',2)
hold on
plot(C_tick_time,Jerk_x,'b','LineWidth',2)
hold on
plot(C_tick_time,Jerk_x_Up_Limit,'r--','LineWidth',2)
hold on
plot(C_tick_time,Jerk_x_Low_Limit,'r--','LineWidth',2)
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Lon.Jerk (mps3)','fontsize',14,'FontWeight','bold')
ylim([min([Jerk_x;Jerk_x_Low_Limit])-2 max([Jerk_x;Jerk_x_Up_Limit])+2])
ylim([-5.5 5.5])
grid;


subplot(234)
plot(C_tick_time,orginal.Ax_HV_mps2,'g','LineWidth',2)
hold on
plot(C_tick_time,Ax_HV_mps2,'b','LineWidth',2)
hold on
plot(C_tick_time,Ax_Up_Limit,'r--','LineWidth',2)
hold on
plot(C_tick_time,Ax_Low_Limit,'r--','LineWidth',2)
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('Lon.Accel (mps2)','fontsize',14,'FontWeight','bold')
% ylim([min([Ax_HV_mps2;Ax_Low_Limit])-2 max([Ax_HV_mps2;Ax_Up_Limit])+2])
ylim([-5.5 5.5])
legend('original','proposed','ISO limit','fontsize',8)
grid;

subplot(236)
plot(C_tick_time,orginal.TTC,'g','LineWidth',2)
hold on
plot(C_tick_time,TTC,'b','LineWidth',2)
xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
ylabel('TTC (sec)','fontsize',14,'FontWeight','bold')
ylim([0 15])
legend('original','proposed')
grid;

% subplot(236)
% plot(C_tick_time,Acc_Mode,'b','LineWidth',2)
% xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
% ylabel('Mode','fontsize',14,'FontWeight','bold')
% ylim([-0.5 1.5])
% text(min(C_tick_time)+15,1.35,'0 - Speed MODE')
% text(min(C_tick_time)+15,1.15,'1 - TH MODE')
% grid;

% subplot(236)
% plot(C_tick_time,(TH-TH_ref),'b','LineWidth',2)
% xlabel('Time (sec)','fontsize',14,'FontWeight','bold')
% ylabel('TH_e_r_r_o_r','fontsize',14,'FontWeight','bold')
% ylim([min(TH-TH_ref)-0.2 max(TH-TH_ref)+0.2])
% grid;

set(gcf,'unit', 'centimeters', 'position',[15 2.8 23.6 13.6]);

%%

%%

% speed error
m=find(Acc_Mode==0);
n=length(m);

speed_error=HV_kph(m(1):m(end))-V_ref_kph(1);
sqrt((sum(speed_error.^2))/(n))
min(speed_error(1:end),[],'all')

% TH error
m1=find(Acc_Mode==1);
n1=length(m1);
TH_error1=TH(m1(1):m1(14))-TH_ref(1);
TH_error2=TH(m1(14+1):m1(end))-TH_ref(1);
sqrt((sum(TH_error1.^2)+sum(TH_error2.^2))/(n1))
min([TH_error1(1:end);TH_error2(1:end)],[],'all')
max([TH_error1(1:end);TH_error2(1:end)],[],'all')