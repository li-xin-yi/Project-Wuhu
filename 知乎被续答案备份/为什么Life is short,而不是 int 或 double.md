# 为什么 "Life is short"，而不是 int 或 double？

原回答地址：https://www.zhihu.com/question/33311526/answer/74111845

**life**是以秒（*Second*）计算的。

比如我们算一个89岁的老人的生命那么就有89\*365\*24\*60\*60=2806704000超过了`signed int`的最大值`2^15-1`，当然不能用`short`了，但没有超过`unsigned int`的最大范围`2^16-1`。

```cpp
class TheElder{
	private: unsigned int life; 
			 int VisitedCountries; 
			 int Languages;
			 int MusicalInstruments;
			 …… 
	public: TheElder(int time,int CountryNumber,int LanguageNumber,int MusicalInstrumentNumber);
			 void Recite(string title="GettysburgAddress" ); 
			 void CombHair(); void ApplyForProfessor();
			 void PlayWithThreeOwls(); 
			  …… 
};
```

那我们就可以这样定义一个类了。可是**life**不应该是一个只与时间相关的字段，中国有句老话叫*事在人为*。

```cpp
class Hasi { 
	private: static time_t HisLife;
	 		 time_t MyLife; 
	 		 int LevelOfKnowledge; 
	 		 int SilentDays;
	public: Hasi(time_t life) :MyLife(life) {} bool RejuvenateForHim(); 
		    bool WearRedClothes(); 
};
		    
bool Hasi::RejuvenateForHim() {
	 if (HisLife>0) {
	 	 HisLife++;
	 	 cout << "Excited! +1 Sec!" << endl; 
	 	 return true; 
	 	} 
	 else {
	  	cout << "I'm angry!" << endl;
	    return false;
	    }
}

bool Hasi::WearRedClothes() {
 	 if (MyLife>0) { 
 	 	HisLife += MyLife / 2.0;
 	 	MyLife /= 2.0; 
 	 	return true;
 	 	}
 	 	return false;
}

time_t GetHisCurrentLife() {
 	struct tm* birth = new tm();
 	time_t time=0; 
 	birth->tm_year = 1926-1900;
 	birth->tm_mon = 8 - 1;
 	birth->tm_mday = 17 - 1;
 	birth->tm_hour = 3;
 	birth->tm_min = 0;
 	birth->tm_sec = 1;
 	birth->tm_wday = 1;
 	birth->tm_yday = 260;
 	time = mktime(birth);
 	delete birth;
 	return time;
 } 

time_t Hasi::HisLife = GetHisCurrentLife();
```

`time_t`也是用以秒计时的一种数据类型，实际上就是`long`，微软钦定用这个类型来表示时间，必然有他们的道理。这些方法也可以充分说明人定胜天。

>一尺之棰,日取其半,万世不竭

——《庄子·天下篇》

既然大家都那么热情的给他增加生命，那么`long`也是不够的，早晚会溢出的。我们这个样子是不行的，所以必须开拓一下思路。

```cpp
enum lifetime{
	finite, infinite
	};
enum Language{
	Chinese, English, Japanese, Romanian, Russian, Spanish, French 
	};
  …… 
class TheElder{
	private: lifetime life;
	set<Language> languages;
	……
	public: TheElder():
	life(infinite){}
	……
}; 

class CommonPerson{
	private: lifetime life;
	Language NativeLanguage;
	……
	public:
	CommonPerson():life(finite){}
	……
};
```
>小知不及大知，小年不及大年。奚以知其然也？朝菌不知晦朔，蟪蛄不知春秋，此小年也。楚之南有冥灵者，以五百岁为春，五百岁为秋。上古有大椿者，以八千岁为春，八千岁为秋。此大年也。而彭祖乃今以久特闻，众人匹之。不亦悲乎！

——《逍遥游》

当我们这些生命时长可以用数字计算的人在讨论**life**到底用什么数据类型可以存放的时候，生命时间无法用数值表达的人轻轻一推黑框眼镜，嘲笑道，你们啊，肤浅。我们对世界的认知总是逃不出自我的局限，因为我们都是普通人啊，怎么能去以我们的方式去理解一个不普通的生命呢？