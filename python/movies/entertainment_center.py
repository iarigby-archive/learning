import media
import fresh_tomatoes

toy_story = media.Movie("Toy Story",
                        "A story of a boy and his toys that come to life",
                        "https://vignette4.wikia.nocookie.net/pixar/images/4/4c/Toy-story-movie-posters-4.jpg/revision/latest?cb=20160329080002",
                        "https://www.youtube.com/watch?v=KYz2wyBy3kc")

#print(toy_story.storyline)

avatar = media.Movie("Avatar",
                     "A marine on an alien planet",
                     "https://upload.wikimedia.org/wikipedia/en/b/b0/Avatar-Teaser-Poster.jpg",
                     "https://www.youtube.com/watch?v=5PSNL1qE6VY")
#print(avatar.storyline)

the_last_jedi = media.Movie("Star Wars",
                        "8th movie in Star Wars Franchise",
                        "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQqz7Fqw0RRHKAAnFMmIbWUAFu7syanWJQqv5I_KTZP31n796DM",
                        "https://www.youtube.com/watch?v=Q0CbN8sfihY")
                            
                    
movies = [toy_story, avatar, the_last_jedi]
#fresh_tomatoes.open_movies_page(movies)
print(media.Movie.__module__)
             
        
