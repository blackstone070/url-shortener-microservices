from locust import HttpUser, task, between

class URLUser(HttpUser):
    # Users wait 1 to 2 seconds between clicks
    wait_time = between(1, 2)

    @task(1)
    def shorten_link(self):
        # Stress test the C++ Encoder
        self.client.post("/shorten", json={"target_url": "https://google.com"})

    @task(3)
    def visit_link(self):
        # Stress test the Redis Cache & Postgres
        # Use a short_code that ALREADY exists in your DB (like '2')
        self.client.get("/2") 
