select a.id from weather as a, weather as b
where datediff(a.recordDate,b.recordDate)=1 
and a.temperature>b.temperature;